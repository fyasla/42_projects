/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:58:09 by fbougama          #+#    #+#             */
/*   Updated: 2021/09/30 15:30:32 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strclen(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	*ft_strcdup(const char *s1, char c)
{
	size_t	len;
	char	*cpy;

	len = ft_strclen(s1, c);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	cpy = ft_memcpy(cpy, s1, len);
	if (!cpy)
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

static	void	*freebuffs(char **buff)
{
	char	**tmp;

	tmp = buff;
	while (*tmp)
	{
		free(*tmp);
		tmp = tmp + sizeof(char *);
	}
	free(*tmp);
	free(buff);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	n;
	t_inc_couple	p;

	p.j = 0;
	p.i = 0;
	tab = malloc((ft_cpt_words(s, c) + 1) * sizeof(char *));
	if (s == NULL || !tab)
		return (NULL);
	while (s[p.i])
	{
		while (s[p.i] == c)
			p.i++;
		if (s[p.i] && s[p.i] != c)
		{
			n = ft_strclen(s + p.i, c);
			tab[p.j] = (char *)ft_strcdup(s + p.i, c);
			if (!tab[p.j])
				return (freebuffs(tab));
			p.i += n;
			p.j++;
		}
	}
	tab[p.j] = NULL;
	return (tab);
}
