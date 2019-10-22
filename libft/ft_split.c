/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:58:09 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/22 17:29:03 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strclen(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void			*ft_strcdup(const char *s1, char c)
{
	size_t	len;
	char	*cpy;

	len = ft_strclen(s1, c);
	if (!(cpy = malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (!(cpy = ft_memcpy(cpy, s1, len)))
		return (NULL);
	cpy[len] = '\0';
	return (cpy);
}

static unsigned int	ft_cpt_words(char const *s, char c)
{
	unsigned int	n;

	n = 0;
	if (!s)
		return (0);
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

static	void		*freebuffs(char **buff)
{
	char **tmp;

	tmp = buff;
	while (*tmp)
		free(tmp++);
	free(buff);
	return (0);
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
	if (s == NULL || !(tab = malloc((n + 1) * sizeof(char*))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			n = ft_strclen(s + i, c);
			if (!(tab[j++] = (char*)ft_strcdup(s + i, c)))
				return (freebuffs(tab));
			i += n;
		}
	}
	tab[j] = NULL;
	return (tab);
}
