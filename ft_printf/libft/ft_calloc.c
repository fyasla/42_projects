/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:35:41 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/28 11:27:04 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	tot;

	tot = size * count;
	if (tot == 0)
		tot = 1;
	if (!(ptr = malloc(tot)))
		return (NULL);
	ft_bzero(ptr, tot);
	return (ptr);
}
