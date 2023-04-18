/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:06:33 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/15 12:38:34 by lefreydier       ###   ########.fr       */
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
# include <errno.h>

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
	pid_t			process;
	char			**cmd;
	struct s_child	*next;
}	t_child;

typedef struct s_pipex
{
	t_child	*child;
	int		tube[2];
	int		infile;
	int		outfile;
	char	**path;
	char	**env;
}	t_pipex;

//	PARSE
t_pipex	*ft_parse(int narg, char **av, char **env);
t_pipex	*ft_init(int narg, char **av);
void	ft_get_paths(t_pipex *pipex);

//	PIPEX
void	ft_pipex(t_pipex *pipex, char **av);
void	child_1_process(int f1, char *cmd);

//	EXIT
void	ft_exit(t_pipex *pipex, char *msg);
void	ft_error_exit(t_pipex *pipex, char *err);
void	ft_free_pipex(t_pipex *pipex);

#endif
