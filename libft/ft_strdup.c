/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:02:04 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/23 12:42:49 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	if (!(ptr = malloc(len * sizeof(char))))
		return (NULL);
	return ((char *)ft_memcpy(ptr, s1, len));
}
