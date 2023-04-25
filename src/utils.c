/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:08:25 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/25 19:47:02 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex	*init_struct(int ac, char **av, char **envp)
{
	t_pipex	*infos;

	infos = ft_calloc(sizeof(*infos), 1);
	if (!infos)
		return (ft_exit(NULL, ERR_MAL), NULL);
	infos->infile = av[1];
	infos->outfile = av[ac - 1];
	infos->env = envp;
	infos->ncmd = ac - 3;
	parse_cmd(infos, av);
	return (infos);
}

char	**get_paths(t_pipex *infos)
{
	char		*env_path;
	char		**paths;
	int			i;

	i = 0;
	if (!infos->env)
		ft_exit(infos, ERR_ENV);
	while (infos->env[i])
	{
		env_path = ft_strnstr(infos->env[i], "PATH=", 5);
		if (env_path)
			break ;
		i++;
	}
	if (!env_path)
		ft_exit(infos, ERR_ENV);
	paths = ft_split(env_path + 5, ':');
	if (!paths)
		ft_exit(infos, ERR_ENV);
	return (paths);
}

void	parse_cmd(t_pipex *infos, char **av)
{
	int	i;

	infos->cmds = ft_calloc(sizeof(*infos->cmds), infos->ncmd);
	if (!infos->cmds)
		ft_exit(infos, ERR_MAL);
	i = -1;
	while (++i < infos->ncmd)
	{
		infos->cmds->cmd = ft_split(av[i + 2], ' ');
		if (!infos->cmds->cmd || !(*infos->cmds->cmd))
			ft_exit(infos, ERR_MAL);
	}
}
