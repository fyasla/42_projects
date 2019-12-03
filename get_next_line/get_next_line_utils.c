/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 09:56:35 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/03 15:41:04 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(char *ptr, unsigned int n)
{
	if (!ptr)
		return ;
	while (n-- > 0)
		*ptr++ = '\0';
}

int		ft_pos(char c, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	if (!(joined = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1)
		joined[i++] = *s1++;
	while (*s2)
		joined[i++] = *s2++;
	joined[i] = '\0';
	return (joined);
}

char	*ft_substr(char *str, int start, int size)
{
	int		length;
	char	*sub;
	int		i;

	i = 0;
	length = size;
	if (ft_strlen(str) - start < size)
		length = ft_strlen(str) - start;
	if (!(sub = (char*)malloc(length + 1)))
		return (NULL);
	while (i < length)
		sub[i++] = str[start++];
	sub[i] = '\0';
	return (sub);
}
