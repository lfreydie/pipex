/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:13:16 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/27 13:35:54 by lfreydie         ###   ########.fr       */
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
	// int		status;
	int		i;

	pipe(infos->pipefd);
	i = -1;
	while (++i < infos->ncmd)
	{
		// perror(ft_itoa(infos->pipefd[0]));
		// perror(ft_itoa(infos->pipefd[1]));
		infos->cmds[i].pid = fork_process(infos, i);
		// perror(ft_itoa((int)infos->cmds[i].pid));
	}
	close(infos->pipefd[READ]);
	close(infos->pipefd[WRITE]);
	perror(ft_itoa(infos->ncmd));
	// i = -1;
	// while (++i < infos->ncmd)
	// {
	// 	perror(ft_itoa(infos->cmds[i].pid));
	// }
	i = -1;
	// waitpid(infos->cmds[infos->ncmd - 1].pid, &status, 0);
	// perror(ft_itoa(infos->cmds[infos->ncmd - 1].pid));
	while (++i < infos->ncmd)
	{
		perror(ft_itoa(infos->cmds[i].pid));
		wait(0);
	}
	// while (++i < infos->ncmd)
	// {
	// 	perror(ft_itoa(infos->cmds[i].pid));
	// 	waitpid(infos->cmds[i].pid, &status, 0);
	// }
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
		// perror("exec");
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
		if (io_fd[0] < 0)
			perror("open");
	}
	else
	{
		io_fd[0] = dup(infos->pipefd[0]);
		if (io_fd[0] < 0)
			perror("dup");
	}
	if (i == infos->ncmd - 1)
	{
		io_fd[1] = open(infos->outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (io_fd[1] < 0)
			perror("open");
	}
	else
	{
		io_fd[1] = dup(infos->pipefd[1]);
		if (io_fd[1] < 0)
			perror("dup");
	}
	if (dup2(io_fd[0], STDIN_FILENO) < 0)
		perror("dup 1");
	if (dup2(io_fd[1], STDOUT_FILENO) < 0)
		perror("dup 2");
	// perror(ft_itoa(io_fd[0]));
	// perror(ft_itoa(io_fd[1]));
	close(io_fd[0]);
	close(io_fd[1]);
}
