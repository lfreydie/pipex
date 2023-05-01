/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:39:25 by lfreydie          #+#    #+#             */
/*   Updated: 2023/05/01 14:44:50 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit(t_pipex *infos, char *err)
{
	if (err)
		perror(err);
	free_infos(infos);
	exit (1);
}

void	free_infos(t_pipex *infos)
{
	int	i;
	int	j;

	if (infos)
	{
		if (infos->cmds)
		{
			i = -1;
			while (++i < infos->ncmd)
			{
				j = -1;
				while (infos->cmds[i].cmd[++j])
					free(infos->cmds[i].cmd[j]);
				free(infos->cmds[i].cmd);
			}
			free(infos->cmds);
		}
		free(infos);
	}
}

void	close_fds(int fd_1, int fd_2, int fd_3, int fd_4)
{
	close(fd_1);
	close(fd_2);
	close(fd_3);
	close(fd_4);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
