/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:28:55 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/11 15:13:08 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit(char *err, int fd)
{
	if (err && fd == 2)
	{
		perror(ERR);
		perror(err);
	}
	else if (err && fd == 1)
		ft_putstr_fd(err, fd);
	if (fd == 2)
		exit(1);
	exit(0);
}

void	ft_free(t_pipex *pipex)
{
	(void)pipex;
}
