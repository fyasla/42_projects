/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:16:30 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/18 12:11:04 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfth"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	len;
	char			*res;

	i = 0;
	len = ft_strlen(s);
	if (!(res = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[i])
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
