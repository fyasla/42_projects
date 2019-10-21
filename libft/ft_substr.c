/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:45 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/19 11:22:20 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(ptr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (start < ft_strlen(s) && len-- > 0 && s[start])
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
