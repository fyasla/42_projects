/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:36:11 by fbougama          #+#    #+#             */
/*   Updated: 2019/07/24 16:01:56 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_in(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_wordlen(char *src, char *charset)
{
	int i;

	i = 0;
	while (src[i] != '\0' && (!ft_is_in(src[i], charset)))
		i++;
	return (i);
}

char	*ft_strdup(char *src, char *charset)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (ft_wordlen(src, charset) + 1))))
		return (NULL);
	while (src[i] && (!(ft_is_in(src[i], charset))))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_count_words(char *str, char *charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_is_in(str[i], charset) == 0 &&
			((ft_is_in(str[i + 1], charset)) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		nb_words;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (str == 0 || charset == 0)
		return (NULL);
	nb_words = ft_count_words(str, charset);
	if ((tab = malloc(sizeof(char*) * nb_words + 1)) == NULL)
		return (NULL);
	while (i < nb_words)
	{
		while (str[j] && ft_is_in(str[j], charset))
			j++;
		tab[i] = ft_strdup(&str[j], charset);
		while (str[j] && (!ft_is_in(str[j], charset)))
			j++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
