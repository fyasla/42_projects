/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:11:45 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/10 15:18:42 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!(ptr = malloc(len * sizeof(char))))
		return (NULL);
	while (s[start] && len-- > 0)
	{
		*ptr++ = s[start++];
	}
	return (ptr);
}
