/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:58:09 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/11 14:37:09 by fbougama         ###   ########.fr       */
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

static void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *) dst;
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}

static void		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s1);
	if (!(cpy = malloc((len + 1) * sizeof(char))))
		return (NULL);
	return(ft_memcpy(cpy, s1, len + 1));
}

static unsigned int	ft_cpt_words(char const *s, char c)
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
	size_t			len;

	len = ft_strlen(s);
	s_cpy = (char*)s;
	n = ft_cpt_words(char const *s, char c);
	if (!(tab = malloc((n + 1)* sizeof(char*))))
		return (NULL);
	while (*s_cpy)
	{
		while (*s_cpy)
		{
			while (*s_cp)
			s_cpy = ft_memccpy(*tab++, s_cpy, c, (s_cpy - s) + len);
		}
	}

	return (tab);
}
