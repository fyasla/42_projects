/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:03:40 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/08 14:54:03 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cpy;
	const char	*s;

	s = src;
	cpy = dst;
	while (n--)
		*cpy++ = *s++;
	return (dst);
}
