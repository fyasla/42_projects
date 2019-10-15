/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:35:35 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/15 16:21:15 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char*)s;
	i = 0;
	while (i < n && *(str + i) != '\0' && *(str + i) != (unsigned char)c)
		i++;
	if (i == n || *(str + i) == '\0')
		return (NULL);
	else
		return ((void*)s + i);
}
