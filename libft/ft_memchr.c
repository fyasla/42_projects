/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:35:35 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/09 16:19:46 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	int		i;

	str = (char*)s;
	i = 0;
	while (i < n && str[i] && str[i] != (unsigned char)c)
		i++;
	if (i == n || !str[i])
		return (NULL);
	else
		return (str + i);
}
