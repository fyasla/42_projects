/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:31:52 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/11 12:24:38 by fbougama         ###   ########.fr       */
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
	int		i;

	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	printf("bjr");
	if (!(ptr = malloc((l1 + l2 + 1) * sizeof(char))))
		return (NULL);
	printf("bjr");
	while (l1-- > 0)
		ptr[i++] = *s1++;
	while (l2-- > 0)
		ptr[i++] = *s2++;
	printf("bjr");
	ptr[i++] = '\0';
	return (ptr);
}
