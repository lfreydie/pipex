/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:06:33 by lfreydie          #+#    #+#             */
/*   Updated: 2023/04/28 12:06:01 by lfreydie         ###   ########.fr       */
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

typedef struct s_cmd
{
	pid_t	pid;
	char	**cmd;
}	t_cmd;

typedef struct s_pipex
{
	t_cmd	*cmds;
	char	**env;
	char	*infile;
	char	*outfile;
	int		pipefd[2];
	int		tmp_fdin;
	int		ncmd;
}	t_pipex;

//	PIPEX
void	pipex_process(t_pipex *infos);
pid_t	fork_process(t_pipex *infos, int i);
void	redir(t_pipex *infos, int i);

//	EXEC
char	*get_path_cmd(char *paths, char *cmd);
void	execute(t_pipex *infos, int i);

//	UTILS
t_pipex	*init_struct(int ac, char **av, char **envp);
char	**get_paths(t_pipex *infos);
void	parse_cmd(t_pipex *infos, char **av);

//	EXIT
void	ft_exit(t_pipex *infos, char *err);
void	free_infos(t_pipex *infos);
void	close_fds(int fd_1, int fd_2, int fd_3, int fd_4);
void	free_tab(char **tab);

#endif
