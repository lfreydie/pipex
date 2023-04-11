/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:12:31 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/10 19:04:19 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (!env | !env[0])
		return (ft_exit(ERR_ENV, 2));
	pipex = ft_parse(ac - 1, av + 1, env);
	pipex.infile = open(av[1], O_RDONLY);
	pipex.outfile = open(av[1], O_CREAT | O_RDWR | O_TRUNC, 0744);
	if (f1 < 0 || f2 < 0)
		return (ft_exit(ERR_NOP, 2));
	pipex(f1, f2, av, env);
}
