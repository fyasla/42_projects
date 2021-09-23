/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 22:20:09 by faysal            #+#    #+#             */
/*   Updated: 2021/09/23 03:40:09 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	child_process(int infile, char *cmd, char **ep, int *end)
{
	char	*cmd_path;
	char	**argv;

	if (infile == -1)
		handle_error();
	dup2(end[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(end[0]);
	cmd_path = find_path(cmd, env_path(ep));
	argv = ft_split(cmd, ' ');
	if (execve(cmd_path, argv, ep) < 0)
		handle_error();
	free(argv);
	free(cmd_path);
}

void	parent_process(int outfile, char *cmd, char **ep, int *end)
{
	char	*cmd_path;
	char	**argv;
	int		status;

	waitpid(-1, &status, 0);
	if (outfile == -1)
		handle_error();
	dup2(end[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(end[1]);
	cmd_path = find_path(cmd, env_path(ep));
	argv = ft_split(cmd, ' ');
	if (execve(cmd_path, argv, ep) < 0)
		handle_error();
	free(argv);
	free(cmd_path);
}

void	pipex(int infile, int outfile, char **av, char **ep)
{
	int		end[2];
	pid_t	parent;
	char	*cmd1;
	char	*cmd2;

	cmd1 = av[2];
	cmd2 = av[3];
	if (pipe(end) == -1)
		handle_error();
	parent = fork();
	if (parent < 0)
		handle_error();
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

	if (ac != 5)
		return (1);
	infile = open(av[1], O_RDONLY);
	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
		handle_error();
	pipex(infile, outfile, av, ep);
	return (0);
}
