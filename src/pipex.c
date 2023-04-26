/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:13:16 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/26 18:06:49 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*infos;

	if (ac < 5)
		return (ft_putstr_fd(ERR_ARG, 2), 127);
	if (!envp)
		ft_exit(NULL, ERR_ENV);//checker
	infos = init_struct(ac, av, envp);
	pipex_process(infos);
	free_infos(infos);
	return (0);
}

void	pipex_process(t_pipex *infos)
{
	int		status;
	int		i;

	pipe(infos->pipefd);
	i = -1;
	while (++i < infos->ncmd)
	{
		infos->cmds[i].pid = fork_process(infos, i);
		perror(ft_itoa((int)infos->cmds[i].pid));
	}
	close(infos->pipefd[READ]);
	close(infos->pipefd[WRITE]);
	i = -1;
	// waitpid(infos->cmds[infos->ncmd - 1].pid, &status, 0);
	// while (++i < infos->ncmd - 1)
	// 	wait(NULL);
	while (++i < infos->ncmd)
	{
		waitpid(infos->cmds[i].pid, &status, 0);
	}
}

pid_t	fork_process(t_pipex *infos, int i)
{
	pid_t	pid;

	redir(infos, i);
	pid = fork();
	if (pid < 0)
		return (perror("FORK"), 0);
	if (pid == 0)
	{
		close(infos->pipefd[READ]);
		close(infos->pipefd[WRITE]);
		execute(infos, i);
		ft_exit(infos, "EXEC");
	}
	return (pid);
}

void	redir(t_pipex *infos, int i)
{
	int	io_fd[2];

	if (i == 0)
	{
		io_fd[0] = open(infos->infile, O_RDONLY);
		perror(ft_itoa(io_fd[0]));
		if (io_fd[0] < 0)
			perror("open");
	}
	else
	{
		dup2(infos->pipefd[0], io_fd[0]);
	}
	if (i == infos->ncmd - 1)
	{
		io_fd[1] = open(infos->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
		perror(ft_itoa(io_fd[1]));
		if (io_fd[1] < 0)
			perror("open");
	}
	else
	{
		dup2(infos->pipefd[1], io_fd[1]);
	}
	if (dup2(io_fd[0], STDIN_FILENO) < 0)
		perror("dup 1");
	if (dup2(io_fd[1], STDOUT_FILENO) < 0)
		perror("dup 2");
	close(io_fd[0]);
	close(io_fd[1]);
}
