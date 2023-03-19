/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:47:08 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/23 12:44:13 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;
	char		*end_s;
	char		*end_d;

	if (!dst && !src)
		return (NULL);
	s = src;
	d = dst;
	end_s = (char*)s + (len - 1);
	end_d = d + (len - 1);
	if (d < s)
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	else
	{
		while (len--)
			*end_d-- = *end_s--;
	}
	return (dst);
}
