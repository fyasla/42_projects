/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:09:54 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/18 12:04:41 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_is_in(char c, char const *str)
{
	char	*str2;

	str2 = (char*)str;
	while (*str2)
	{
		if (*str2++ == c)
			return (1);
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;
	size_t			size;
	char			*res;

	end = ft_strlen(s1) - 1;
	start = 0;
	while (ft_is_in(s1[start], set))
		start++;
	while (ft_is_in(s1[end], set) && end > 0)
		end--;
	size = end - start + 1;
	if (end < start)
		return ((char*)s1 + start);
	if (!(res = ft_substr(s1, start, size)))
		return (NULL);
	return (res);
}
