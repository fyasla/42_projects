/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:03:40 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/23 12:43:09 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cpy;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	s = src;
	cpy = dst;
	while (n-- > 0)
		*cpy++ = *s++;
	return (dst);
}
