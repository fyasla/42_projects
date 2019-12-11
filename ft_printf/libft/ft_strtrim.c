/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:09:54 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/30 13:34:42 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_is_in(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		len;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_is_in(s1[i], set))
		i++;
	if (!s1[i])
		return (ft_calloc(1, 1));
	start = i;
	i = ft_strlen(s1) - 1;
	while (ft_is_in(s1[i], set))
		i--;
	len = i - start + 1;
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
