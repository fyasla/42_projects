/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 22:18:13 by faysal            #+#    #+#             */
/*   Updated: 2021/09/23 02:17:12 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>

// //pipex_utils.c
// char	*env_path(char **ep);
// char	*find_path(char *cmd, char *path);

// //main.c
// void	child_process(int infile, char *cmd, char **ep, int *end);
// void	parent_process(int outfile, char *cmd, char **ep, int *end);
// void	pipex(int infile, int outfile,  char *cmd1, char *cmd2, char **ep);
// int		main(int ac, char **av, char **ep);

//main.c
void	child_process(int outfile, char *cmd, char **ep, int *end);
void	parent_process(int outfile, char *cmd, char **ep, int *end);
void	pipex(int infile, int outfile,  char *cmd1, char *cmd2, char **ep);
int		main(int argc, char **argv, char **envp);

//pipex_utils.c
char	*env_path(char **ep);
char	*find_path(char *cmd, char *path);
void	error(void);
#endif
