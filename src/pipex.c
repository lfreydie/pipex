/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:13:16 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/24 18:39:04 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av)
{
	int		f_in;
	int		f_out;

	if (ac < 5)
		return (ft_putstr_fd(ERR_ARG, 2), 127);
	f_in = open(av[1], O_RDONLY);
	if (f_in < 0)
		return (perror("open"), errno);
	f_out = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f_out < 0)
		return (close(f_in), perror("open"), errno);
	pipex_process(f_in, f_out, ac, av);
}

void	pipex_process(int f_in, int f_out, int ac, char **av)
{
	int		status;
	int		pipefd[2];
	pid_t	*pid_tab;
	int		i;

	i = 2;
	pipe(pipefd);
	pid_tab = ft_calloc(ac - 3, sizeof(*pid_tab));
	if (!pid_tab)
		perror("calloc");
	pid_tab[0] = fork_process(pipefd, f_in, av[2], 1);
	while (++i < ac - 2)
		pid_tab[i - 2] = fork_process(pipefd, 0, av[i], 2);
	pid_tab[ac - 2] = fork_process(pipefd, f_out, av[ac - 2], 3);
	close(pipefd[READ]);
	close(pipefd[WRITE]);
	i = -1;
	while (++i < ac - 2)
		waitpid(pid_tab[i], &status, 0);
}

pid_t	fork_process(int pipefd[2], int file, char *cmd, int child)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (perror("fork"), 0);
	if (pid == 0)
		child_process(file, pipefd, cmd, child);
	return (pid);
}

void	child_process(int file, int pipefd[2], char *cmd, int child)
{
	if (child == 1)
	{
		if (dup2(file, STDIN_FILENO) < 0)
			perror("dup2");
	}
	else
	{
		if (dup2(pipefd[READ], STDIN_FILENO) < 0)
			perror("dup2");
	}
	if (child == 3)
	{
		if (dup2(file, STDOUT_FILENO) < 0)
			perror("dup2");
	}
	else
	{
		if (dup2(pipefd[WRITE], STDOUT_FILENO) < 0)
			perror("dup2");
	}
	close(pipefd[WRITE]);
	close(pipefd[READ]);
	execute(cmd);
	exit(EXIT_FAILURE);
}
