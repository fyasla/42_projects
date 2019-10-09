/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:08:51 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/09 16:31:13 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	int			i;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (str1[i] == str2[i] && n-- > 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
