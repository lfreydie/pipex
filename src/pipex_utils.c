/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:26:46 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/24 17:43:35 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**get_paths(void)
{
	extern char	**environ;
	char		*env_path;
	char		**paths;
	int			i;

	i = 0;
	if (!environ)
		perror("envp");
	while (environ[i])
	{
		env_path = ft_strnstr(environ[i], "PATH=", 5);
		if (env_path)
			break ;
		i++;
	}
	if (!env_path)
		perror("path not found");
	paths = ft_split(env_path + 5, ':');
	if (!paths)
		perror("split");
	return (paths);
}

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

void	execute(char *cmd)
{
	char		**cmd_cut;
	char		**paths;
	char		*path_cmd;
	extern char	**environ;
	int			i;

	i = 0;
	cmd_cut = ft_split(cmd, ' ');
	if (!cmd_cut || !(*cmd_cut))
		perror("split");
	paths = get_paths();
	if (!paths)
		perror("split");
	while (paths[i])
	{
		path_cmd = get_path_cmd(paths[i], cmd_cut[0]);
		execve(path_cmd, cmd_cut, environ);
		free(path_cmd);
		i++;
	}
	free_tab(cmd_cut);
	free_tab(paths);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
