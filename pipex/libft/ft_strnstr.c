/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:33:03 by fbougama          #+#    #+#             */
/*   Updated: 2021/09/02 17:34:02 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;
	int		i;
	size_t	haystack_len;
	size_t	j;

	if (!haystack && !needle)
		return (NULL);
	needle_len = ft_strlen((char *)needle);
	haystack_len = ft_strlen((char *)haystack);
	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i + needle_len <= haystack_len && i + needle_len <= n)
	{
		j = 0;
		while (j < n && haystack[i + j] == needle[j])
			j++;
		if (j == n || needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
