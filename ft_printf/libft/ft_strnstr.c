/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:33:03 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/28 12:09:02 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *nd, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (*nd == '\0')
		return ((char *)h);
	if (h == NULL && len == 0)
		return (NULL);
	while (*h && l < len)
	{
		while (h[i] && h[i] == nd[i] && i + l < len)
			i++;
		if (nd[i] == '\0')
			return ((char *)h);
		else
			i = 0;
		h++;
		l++;
	}
	return (0);
}
