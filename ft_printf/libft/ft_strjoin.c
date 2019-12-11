/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:31:52 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/28 11:54:51 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;

	i = 0;
	if (!s1 || !s2 || !(joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1)
		joined[i++] = *s1++;
	while (*s2)
		joined[i++] = *s2++;
	joined[i] = '\0';
	return (joined);
}
