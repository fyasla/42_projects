/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:03:40 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/28 10:42:20 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cpy;
	char	*s;

	if (!dst && !src)
		return (NULL);
	s = (char*)src;
	cpy = (char*)dst;
	while (n-- > 0)
		*cpy++ = *s++;
	return (dst);
}
