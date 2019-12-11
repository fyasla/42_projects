/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:58:09 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/28 11:51:32 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cpt_words(char const *s, char c)
{
	int	n;

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

static	char	*bet_strcpy(char const *start, char *end)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	while (start < end)
		str[i++] = *start++;
	str[i] = '\0';
	return (str);
}

static	void	*freebuffs(char **buff)
{
	char **tmp;

	tmp = buff;
	while (*tmp)
		free(tmp++);
	free(buff);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	char	*ptr;
	char	*s_cpy;

	i = 0;
	s_cpy = (char *)s;
	ptr = (char *)s_cpy;
	if (!s || !(tab = malloc(sizeof(char *) * (ft_cpt_words(s, c) + 1))))
		return (NULL);
	while (*s_cpy && i < ft_cpt_words(s, c))
	{
		while (*ptr && *ptr != c)
			ptr++;
		if (ptr - s_cpy > 0)
		{
			if (!(tab[i++] = bet_strcpy(s_cpy, ptr)))
				return (freebuffs(tab));
			s_cpy = ptr;
		}
		if (*ptr++ != '\0')
			s_cpy++;
	}
	tab[i] = NULL;
	return (tab);
}
