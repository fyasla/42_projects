/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:56:11 by fbougama          #+#    #+#             */
/*   Updated: 2021/09/02 17:32:57 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	char	*dst2;
	char	*src2;

	src2 = (char *)src;
	dst2 = dst;
	i = 0;
	while (i++ < dstsize && *dst2 != '\0')
		dst2++;
	len = dst2 - dst;
	if (dstsize - len == 0)
		return (len + ft_strlen(src));
	i = len;
	while (*src2 != '\0')
	{
		if (i++ < dstsize - 1)
		{
			*dst2 = *src2;
			dst2++;
		}
		src2++;
	}
	*dst2 = '\0';
	return (len + src2 - src);
}
