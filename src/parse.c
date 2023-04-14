/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:12:16 by lefreydier        #+#    #+#             */
/*   Updated: 2023/04/14 15:15:15 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_pipex	*ft_parse(int narg, char **av, char **env)
{
	t_pipex	*pipex;

	if (narg != 5)
		return (ft_exit(ERR_ARG, 2), NULL);
	pipex = ft_init();
	pipex->infile = open(av[1], O_RDONLY);
	pipex->outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0744);
	if (pipex->infile < 0 || pipex->outfile < 0)
		return (ft_free(pipex), ft_exit(ERR_NOP, 2), NULL);
	pipex->env = env;
	ft_get_paths(pipex);
	return (pipex);
}

t_pipex	*ft_init(void)
{
	t_pipex	*pipex;

	pipex = ft_calloc(sizeof(*pipex), 1);
	if (!pipex)
		return (ft_exit(ERR_MAL, 2), NULL);
	pipex->child = ft_calloc(sizeof(*pipex->child_1), 1);
	pipex->child->next = ft_calloc(sizeof(*pipex->child_2), 1);
	if (!pipex->child_1 || !pipex->child_2)
		return (ft_free(pipex), ft_exit(ERR_MAL, 2), NULL);
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
