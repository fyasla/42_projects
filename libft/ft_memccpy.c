/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:17:57 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/09 14:37:35 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*s;
	char		*cpy;

	s = src;
	cpy = dst;
	while (n-- > 0)
	{
		*cpy++ = *s++;
		if (*(s - 1) == (char)c)
			return (cpy);
	}
	return (NULL);
}
