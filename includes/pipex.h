/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:06:33 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/24 18:39:08 by lfreydie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

# define ERROR 1
# define SUCCESS 0
# define READ 0
# define WRITE 1
# define ERR "Error\n"
# define ERR_ARG "Invalid number of arguments\n"
# define ERR_CMD "Command not found\n"
# define ERR_PIP "Pipe didn't work\n"
# define ERR_MAL "Malloc didn't work\n"
# define ERR_ENV "Environnement error\n"
# define ERR_NOP "The file doesn't open or isn't a file\n"

//	PIPEX
void	pipex_process(int f_in, int f_out, int ac, char **av);
pid_t	fork_process(int pipefd[2], int file, char *cmd, int child);
void	child_process(int file, int pipefd[2], char *cmd, int child);


//	PIPEX_UTILS
char	**get_paths(void);
char	*get_path_cmd(char *paths, char *cmd);
void	execute(char *cmd);
void	free_tab(char **tab);

#endif
