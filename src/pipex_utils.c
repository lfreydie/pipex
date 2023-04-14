/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:43:45 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/14 14:58:40 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_cmd(t_pipex *pipex, char *cmd)
{
	pipex->child->cmd = ft_split(cmd, ' ');
	if (!pipex->child->cmd)
		perror("split");
}

char	*get_path_cmd(t_pipex *pipex, int i)
{
	char	*tmp;
	char	*rslt;

	tmp = ft_strjoin(pipex->path[i], "/");
	rslt = ft_strjoin(tmp, pipex->child->cmd[0]);
	return ()
}
