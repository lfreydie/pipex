/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:28:55 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/14 15:14:54 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit(t_pipex *pipex, char *msg)
{
	if (msg)
		ft_putstr(msg);
	ft_free_pipex(pipex);
	exit(0);
}

void	ft_error_exit(t_pipex *pipex, char *err)
{
	if (err)
		perror(err);
	else
		strerror(errno);
	ft_free(pipex);
	exit(1);
}

void	ft_free_pipex(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->child)
			ft_free_child(pipex->child);
		if 
	}
}

void	ft_free_child(t_child *child)
{

}
