/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:31:52 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/23 12:43:34 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*ptr;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(ptr = malloc((l1 + l2 + 1) * sizeof(char))))
		return (NULL);
	while (l1-- > 0)
		ptr[i++] = *s1++;
	while (l2-- > 0)
		ptr[i++] = *s2++;
	ptr[i++] = '\0';
	return (ptr);
}
