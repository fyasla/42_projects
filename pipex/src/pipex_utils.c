/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 23:35:59 by faysal            #+#    #+#             */
/*   Updated: 2021/09/23 02:19:15 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*env_path(char **ep)
{
	int	i;

	i = 0;
	while (ft_strnstr(ep[i], "PATH", 4) == NULL)
		i++;
	return (ft_strnstr(ep[i], "PATH", 4));
}

char	*find_path(char *cmd, char *path)
{
	char	**all_paths;
	int		i;
	char	*cmd_no_arg;
	char	*try_path;
	char	*tmp;

	cmd_no_arg = ft_split(cmd, ' ')[0];
	all_paths = ft_split(path, ':');
	i = 0;
	while (all_paths[i] != NULL)
	{
		tmp = ft_strjoin(all_paths[i], "/");
		try_path = ft_strjoin(tmp, cmd_no_arg);
		free(tmp);
		if (access(try_path, F_OK) == 0)
			return (try_path);
		i++;
	}
	return (NULL);
}

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}
