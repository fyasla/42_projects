/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:35:41 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/10 13:51:20 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n-- > 0)
		*str++ = '\0';
}

void		*calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	tot;

	tot = size * count;
	if (tot == 0)
		tot = 1;
	if (ptr = malloc(tot))
		ft_bzero(ptr, tot);
	return (ptr);
}
