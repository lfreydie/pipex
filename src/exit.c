/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:28:55 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/10 16:14:48 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit(char *err, int fd)
{
	if (err)
	{
		if (fd == 2)
			ft_putstr_fd(ERR, fd);
		ft_putstr_fd(err, fd);
	}
	if (fd == 2)
		exit(1);
	exit(0);
}
