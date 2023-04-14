/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:08:52 by lefreydier        #+#    #+#             */
/*   Updated: 2023/04/14 14:33:45 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_pipex(t_pipex *pipex, char **av)
{
	pipe(pipex->tube);
	pipex->child_1 = fork();
	if (pipex->child_1 < 0)
		return (perror("fork :"));
	else if (!pipex->child_1)
		child_1_process(, av[2]);
	pipex->child_2 = fork();
	if (pipex->child_2 < 0)
		return (perror("fork :"));
	else if (!pipex->child_2)
		child_2_process(f1, av[2]);
}

void	child_1_process(t_pipex *pipex, char *cmd)
{
	int	i;

	i = 0;
	if (dup2(pipex->infile, STDIN_FILENO) < 0)
		return (perror("dup2"));
	if (dup2(pipex->tube[1], STDOUT_FILENO) < 0)
		return (perror("dup2"));
	get_cmd(pipex, cmd);
	while (pipex->path[i])
	{
		paths = get_path_cmd(pipex, i);
		execve(paths, cmd, pipex->env);
		i++;
	}
	close_all(pipex)
}
