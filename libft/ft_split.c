/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:58:09 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/10 19:59:52 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*s;
	char		*cpy;

	s = src;
	cpy = dst;
	while (n-- > 0 && *s)
	{
		*cpy++ = *s++;
		if (*(s - 1) == (char)c)
			return (cpy);
	}
	return (NULL);
}

unsigned int	ft_cpt_words(char const *s, char c)
{
	unsigned int	n;

	n = 0;
	while (*s)
	{
		if (*s != c)
			n++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (n);
}

char			**ft_split(char const *s, char c)
{
	char			*s_cpy;
	char			**tab;
	unsigned int	n;

	s_cpy = (char*)s;
	n = ft_cpt_words(char const *s, char c);
	if (!(tab = malloc((n + 1)* sizeof(char*))))
		return (NULL);
	while (*s_cpy)
	{
		while *s
	}

	return (tab);
}
