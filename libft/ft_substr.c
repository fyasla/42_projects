/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:45 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/11 11:37:09 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[start] && len-- > 0)
		ptr[i++] = s[start++];
	ptr[i++] = '\0';
	return (ptr);
}
