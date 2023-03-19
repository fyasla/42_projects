/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:30:24 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/28 17:05:19 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

size_t	ft_sl(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *str, size_t start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!str)
		return (NULL);
	if (start + len > ft_sl(str))
		len = ft_sl(str) - start;
	if (!(sub = (char*)malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_bzero(char *ptr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		ptr[i++] = '\0';
	return (ptr);
}

char	*ft_strmove(char const *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!(ptr = malloc((ft_sl(s1) + 1) * sizeof(char))))
		return (NULL);
	while (i <= ft_sl(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strmove(s2));
	if (!s2)
		return (ft_strmove(s1));
	if (!(joined = (char*)malloc(ft_sl(s1) + ft_sl(s2) + 1)))
		return (NULL);
	while (*s1)
		joined[i++] = *s1++;
	while (*s2)
		joined[i++] = *s2++;
	joined[i] = '\0';
	return (joined);
}
