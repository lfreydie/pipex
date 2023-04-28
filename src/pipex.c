/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:13:16 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/28 12:51:56 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*infos;

	if (ac < 5)
		return (ft_putstr_fd(ERR_ARG, 2), 127);
	infos = init_struct(ac, av, envp);
	pipex_process(infos);
	free_infos(infos);
	return (0);
}

void	pipex_process(t_pipex *infos)
{
	int	status;
	int	i;

	i = -1;
	infos->tmp_fdin = open(infos->infile, O_RDONLY);
	if (infos->tmp_fdin < 0)
		perror(infos->infile);
	while (++i < infos->ncmd)
		infos->cmds[i].pid = fork_process(infos, i);
	close(infos->tmp_fdin);
	i = -1;
	waitpid(infos->cmds[infos->ncmd].pid, &status, 0);
	while (++i < infos->ncmd - 1)
		wait(0);
}

pid_t	fork_process(t_pipex *infos, int i)
{
	pid_t	pid;

	if (pipe(infos->pipefd) < 0)
		perror("pipe");
	pid = fork();
	if (pid < 0)
		return (perror("FORK"), 0);
	if (pid == 0)
	{
		redir(infos, i);
		execute(infos, i);
		ft_exit(infos, infos->cmds[i].cmd);
	}
	close(infos->tmp_fdin);
	close(infos->pipefd[1]);
	infos->tmp_fdin = infos->pipefd[0];
	return (pid);
}

void	redir(t_pipex *infos, int i)
{
	int	io_fd;

	if (infos->tmp_fdin >= 0 && dup2(infos->tmp_fdin, STDIN_FILENO) < 0 )
		perror("dup2");
	if (i == infos->ncmd - 1)
	{
		io_fd = open(infos->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (io_fd < 0)
			perror(infos->outfile);
		if (io_fd >= 0 && dup2(io_fd, STDOUT_FILENO) < 0)
			perror("dup2");
		close(io_fd);
	}
	else
	{
		if (dup2(infos->pipefd[1], STDOUT_FILENO) < 0)
			perror("dup2");
	}
	close(infos->tmp_fdin);
	if (i == 0)
		close(infos->pipefd[0]);
	close(infos->pipefd[1]);
}
