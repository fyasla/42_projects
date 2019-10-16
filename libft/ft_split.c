/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:58:09 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/15 19:07:54 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static size_t		ft_strclen(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dst;
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}

static void			*ft_strcdup(const char *s1, char c)
{
	size_t	len;
	char	*cpy;

	len = ft_strclen(s1, c);
	if (!(cpy = malloc((len + 1) * sizeof(char))))
		return (NULL);
	cpy = ft_memcpy(cpy, s1, len);
	cpy[len] = '\0';
	return (cpy);
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

char				**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	n;
	int				i;
	int				j;

	j = 0;
	i = 0;
	n = ft_cpt_words(s, c);
	if (!(tab = malloc((n + 1) * sizeof(char*))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			n = ft_strclen(s + i, c);
			tab[j++] = (char*)ft_strcdup(s + i, c);
			i += n;
		}
	}
	tab[j] = NULL;
	return (tab);
}
