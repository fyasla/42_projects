/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:31:52 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/10 16:39:37 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ptr;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(ptr = malloc((l1 + l2) * sizeof(char))))
		return (NULL);
	while (l1-- > 0)
		*ptr++ = *s1++;
	while (l2-- > 0)
		*ptr++ = *s2++;
	ptr++ = '\0';
	return (ptr);
}
