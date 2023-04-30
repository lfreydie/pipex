/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:26:46 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/30 11:39:25 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_path_cmd(char *paths, char *cmd)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(paths, "/");
	if (!tmp)
		perror("get_path_cmd");
	path = ft_strjoin(tmp, cmd);
	free(tmp);
	if (!path)
		perror("get_path_cmd");
	return (path);
}

void	execute(t_pipex *infos, int i)
{
	char		**paths;
	char		*path_cmd;
	int			n;

	n = 0;
	paths = get_paths(infos);
	while (paths[n])
	{
		path_cmd = get_path_cmd(paths[n], infos->cmds[i].cmd[0]);
		if (!access(path_cmd, F_OK))
		{
			execve(path_cmd, infos->cmds[i].cmd, infos->env);
			perror(path_cmd);
		}
		free(path_cmd);
		n++;
	}
	free_tab(paths);
	return ;
}
