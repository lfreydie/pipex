/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:06:33 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/11 15:34:41 by lefreydier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
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
# define ERR_MAL "Malloc didn't work\n"
# define ERR_ENV "Environnement error\n"
# define ERR_NOP "The file doesn't open or isn't a file\n"

typedef struct s_child
{
	pid_t	child;
	char	*cmd;
	char	**cmd_args;
}	t_child;

typedef struct s_pipex
{
	t_child	*child_1;
	t_child	*child_2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	**path;
	char	**env;
}	t_pipex;

//	PARSE
t_pipex	*ft_parse(int narg, char **av, char **env);
t_pipex	*ft_init(void);
void	ft_get_paths(t_pipex *pipex);

//	PIPEX
// void	ft_pipex(int f1, int f2, char **av, char **env);
// void	child_1_process(int f1, char *cmd);

//	EXIT
void	ft_exit(char *err, int fd);
void	ft_free(t_pipex *pipex);

#endif
