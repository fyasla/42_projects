/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 22:20:09 by faysal            #+#    #+#             */
/*   Updated: 2021/09/23 02:21:23 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process(int infile, char *cmd, char **ep, int *end)
{
	const char	*cmd_path;
	char		**argv;

	if (infile == -1)
		error();
	dup2(end[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(end[0]);
	cmd_path = find_path(cmd, env_path(ep));
	argv = ft_split(cmd, ' ');
	execve(cmd_path, argv, ep);
}

void	parent_process(int outfile, char *cmd, char **ep, int *end)
{
	const char	*cmd_path;
	char		**argv;

	waitpid(-1, NULL, 0);
	if (outfile == -1)
		error();
	dup2(end[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(end[1]);
	cmd_path = find_path(cmd, env_path(ep));
	argv = ft_split(cmd, ' ');
	execve(cmd_path, argv, ep);
}

void	pipex(int infile, int outfile, char *cmd1, char *cmd2, char **ep)
{
	int		end[2];
	pid_t	parent;

	if (pipe(end) == -1)
		error();
	parent = fork();
	if (parent < 0)
		perror("Fork: ");
	if (parent == 0)
		child_process(infile, cmd1, ep, end);
	else
		parent_process(outfile, cmd2, ep, end);
	close(end[0]);
	close(end[1]);
}

int	main(int ac, char **av, char **ep)
{
	int		infile;
	int		outfile;
	char	*cmd1;
	char	*cmd2;

	if (ac != 5)
		return (0);
	infile = open(av[1], O_RDONLY);
	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	cmd1 = av[2];
	cmd2 = av[3];
	if (infile < 0 || outfile < 0)
		return (-1);
	pipex(infile, outfile, cmd1, cmd2, ep);
	return (0);
}
