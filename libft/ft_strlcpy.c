/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:11:24 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/09 19:12:13 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	len_src;
	int		i;

	len_src = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (*src && i++ < dstsize - 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (len_src);
}
