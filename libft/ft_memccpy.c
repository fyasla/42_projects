/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:17:57 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/07 14:40:46 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char		*s;
	char			*cpy;
	int				i;
	unsigned char	c2;

	s = src;
	cpy = dst;
	i = 0;
	while (i++ < n && s[i++] != c)
		cpy[i] = s[i];
	if (i == n)
		return (NULL);
	else
		return (s + i + 1);
}
