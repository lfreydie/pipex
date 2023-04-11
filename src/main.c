/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:12:31 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/11 15:36:43 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int	i;

	i = -1;
	if (!env | !env[0])
		return (ft_exit(ERR_ENV, 2), 1);
	while (env[++i])
		printf("%s\n", env[i]);
	pipex = ft_parse(ac, av, env);
	// ft_pipex(pipex, av);
}
