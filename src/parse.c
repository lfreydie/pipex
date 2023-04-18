/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:12:16 by lefreydier        #+#    #+#             */
/*   Updated: 2023/04/15 12:46:07 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex	*ft_parse(int narg, char **av, char **env)
{
	t_pipex	*pipex;

	if (narg < 5)
		return (ft_error_exit(NULL, ERR_ARG), NULL);
	pipex = ft_init(narg, av);
	pipex->infile = open(av[1], O_RDONLY);
	pipex->outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0744);
	if (pipex->infile < 0 || pipex->outfile < 0)
		return (ft_free(pipex), ft_exit(ERR_NOP, 2), NULL);
	pipex->env = env;
	ft_get_paths(pipex);
	return (pipex);
}

t_pipex	*ft_init(int narg, char **av)
{
	t_pipex	*pipex;
	int		i;

	i = 2;
	pipex = ft_calloc(sizeof(*pipex), 1);
	if (!pipex)
		return (ft_error_exit(NULL, ERR_MAL), NULL);
	while (i < narg - 1)
	{
		if (!pipex->child)
			ft_lstnew(get_cmd(av[i]));
		
		// pipex->child = ft_calloc(sizeof(*pipex->child), 1);
		// if (!pipex->child)
		// 	return (ft_error_exit(pipex, ERR_MAL), NULL);
		i++;
	}
	return (pipex);
}

void	ft_get_paths(t_pipex *pipex)
{
	int		i;
	char	*path;

	i = -1;
	while (pipex->env[++i])
	{
		path = ft_strnstr(pipex->env[i], "PATH=", 5);
		if (path)
		{
			printf("%s\n", path);
			pipex->path = ft_split(path, ' ');
			break ;
		}
	}
	if (!pipex->path)
	{
		ft_free(pipex);
		ft_exit("Couldn't get path\n", 2);
	}
}
