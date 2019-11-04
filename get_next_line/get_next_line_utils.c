/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:39:41 by fbougama          #+#    #+#             */
/*   Updated: 2019/11/02 16:40:56 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if(!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strclen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(ptr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (start < ft_strlen(s) && len-- > 0 && s[start])
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cpy;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	s = src;
	cpy = dst;
	while (n-- > 0)
		*cpy++ = *s++;
	return (dst);
}

char			*ft_strcdup(const char *s1, const char c)
{
	size_t	len;
	char	*ptr;

	len = ft_strclen(s1, c);
	if (!(ptr = malloc((len + 1))))
		return (NULL);
	ptr[len] = '\0';
	return ((char *)ft_memcpy(ptr, s1, len));
}
