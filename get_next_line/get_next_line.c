/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:39:44 by fbougama          #+#    #+#             */
/*   Updated: 2019/11/02 17:58:49 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_is_in(const char c, const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_after_first(char *str, char c)
{
	int		len;
	int 	i;
	char	*after;

	i = 0;
	len = ft_strlen(str);
	while (str[i] && str[i] != c)
		i++;
	if (!(after = malloc (len - i)))
		return (NULL);
	if (i == len)
		return (str);
	while (str[i])
		*after++ = str[i++];
	*after = '\0';
	return (after);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	i = 0;
	if (!s1)
		return ((char*)s2);
	if (!s2)
		return ((char*)s1);
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}

void	*ft_bzero(void *b, size_t len)
{
	unsigned char	*ptr;

	ptr = b;
	while (len-- > 0)
		*ptr++ = 0;
	return (b);
}





#include <stdio.h>



int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*save;

	if (!(buff = malloc (BUFFER_SIZE + 1)) || fd < 0 || BUFFER_SIZE < 1)
	{
		//free(buff);
		return (-1);
	}
	ft_bzero(buff, BUFFER_SIZE + 1);
	if (ft_is_in('\n', save))
	{
		*line = ft_strcdup(save, '\n');
		//printf("line : %s\n address : %p\n", *line, *line);
		save = ft_substr(save, ft_strclen(save, '\n') + 1, ft_strlen(save) - ft_strclen(save, '\n') - 1);
	}
	else if(read(fd, buff, BUFFER_SIZE) < BUFFER_SIZE && !ft_is_in('\n', buff))
	{
		save = ft_strjoin(save, buff);
		*line = ft_strcdup(save, '\n');
		free(save);
		*save = 0;
		free(buff);
		return (0);
	}
	else
	{		
		free(save);
		save = ft_strjoin(save, buff);
		get_next_line(fd, line);
	}
	free(buff);
	return (1);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*int	main(int ac, char **av)
{
	(void)	ac;
	int		fd;
	char	*line;
	int		gnlret;

	fd = open(av[1], O_RDONLY);
	while ((gnlret = get_next_line(fd, &line)) > 0)
	{
	}
	close(fd);
	return (0);
}*/

int        main(int argc, char **argv)
{
    int fd = 0;
    int nbfile = 0;
    int    i = 1;
    char *line = NULL;
    int    retgnl = 1;

    if (argc == 1)
        fd = 1;
    else if (argc > 1)
    {
        nbfile = argc;
        while (i != nbfile)
        {
            fd = open(argv[i],O_RDONLY);
            printf("*-*-*-*-*-*-*-*-*-*\n*-*-*-*-*-*-*-*-*-*\n%s %d %s %s\n*-*-*-*-*-*-*-*-*-*\n",
			"file descriptor", i, ":", argv[i]);
            while ((retgnl = get_next_line(fd, &line)) > 0)
            {
			    //printf("%d       %s\n", retgnl, line);
				free(line);
		   }
			//printf("%d         %s\n", retgnl, line);
			free(line);
            close(fd);
            i++;
        }
    }
	return (0);
}