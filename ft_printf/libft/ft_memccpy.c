/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:17:57 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/28 16:52:25 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*cpy;

	s = (unsigned char*)src;
	cpy = (unsigned char*)dst;
	while (n-- > 0)
	{
		*cpy++ = *s++;
		if (*(s - 1) == (unsigned char)c)
			return (cpy);
	}
	return (NULL);
}
