/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:31:52 by fbougama          #+#    #+#             */
/*   Updated: 2021/09/02 17:38:24 by faysal           ###   ########.fr       */
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
	ptr = malloc((l1 + l2 + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (l1-- > 0)
		ptr[i++] = *s1++;
	while (l2-- > 0)
		ptr[i++] = *s2++;
	ptr[i++] = '\0';
	return (ptr);
}
