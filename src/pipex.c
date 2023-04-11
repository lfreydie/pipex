/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:08:52 by lefreydier        #+#    #+#             */
/*   Updated: 2023/04/11 14:28:15 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void	ft_pipex(int f1, int f2, char **av, char **env)
// {
// 	child_1 = fork();
// 	if (child_1 < 0)
// 		return (perror("fork :"));
// 	else if (!child_1)
// 		child_1_process(f1, av[2]);
// 	child_2 = fork();
// 	if (child_2 < 0)
// 		return (perror("fork :"));
// 	else if (!child_2)
// 		child_2_process(f1, av[2]);
// }

// void	child_1_process(int f1, char *cmd)
// {
// 	if (dup2(f1, STDIN_FILENO) < 0)
// 		return (perror("dup2 :"));
// 	if (dup2(fd[1], STDOUT_FILENO) < 0)
// 		return (perror("dup2 :"));
// }
