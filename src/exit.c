/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:28:55 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/15 12:29:59 by lefreydier       ###   ########.fr       */
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
	ft_free_pipex(pipex);
	exit(1);
}

void	ft_free_pipex(t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->child)
			ft_free_child(pipex->child);
		if (pipex->path)
			ft_free_array(pipex->path);
		free(pipex);
	}
}

void	ft_free_child(t_child *child)
{
	t_child	*tmp;

	if (!child)
		return ;
	while (child)
	{
		tmp = child->next;
		if (child->cmd)
			ft_free_array(child->cmd);
		// What about PID ?
		free(child);
		child = tmp;
	}
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
