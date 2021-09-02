/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:35:41 by fbougama          #+#    #+#             */
/*   Updated: 2021/09/02 17:07:13 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	tot;

	tot = size * count;
	if (tot == 0)
		tot = 1;
	ptr = malloc(tot);
	if (ptr)
		ft_bzero(ptr, tot);
	return (ptr);
}
