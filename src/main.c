/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:12:31 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/13 13:55:50 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (!env | !env[0])
		return (ft_exit(ERR_ENV, 2), 1);
	pipex = ft_parse(ac, av, env);
	// ft_pipex(pipex, av);
}
