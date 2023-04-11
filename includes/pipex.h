/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:06:33 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/10 19:17:25 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ERROR 1
# define SUCCESS 0
# define ERR "Error\n"
# define ERR_ARG "Invalid number of arguments\n"
# define ERR_CMD "Command not found\n"
# define ERR_PIP "Pipe didn't work\n"
# define ERR_ENV "Environnement error\n"
# define ERR_NOP "The file doesn't open or isn't a file\n"

typedef struct s_pipex
{
	pid_t	child_1;
	pid_t	child_2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*cmd;
	char	**cmd_args;
	char	**path;
	char	**env;
}	t_pipex;

//	PARSE
t_pipex	ft_parse(int narg, char *arg, char **env);

//	PIPEX
void	pipex(int f1, int f2, char **av, char **env);
void	child_1_process(int f1, char *cmd);

//	EXIT
void	ft_exit(char *err, int fd);

#endif
