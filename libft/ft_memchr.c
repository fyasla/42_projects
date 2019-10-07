/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:35:35 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/07 15:56:20 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	c2;
	int				i;
	const char		*str;

	c2 = c;
	i = 0;
	while (i < n && str[i])
		i++;
	if (i == n)
		return (NULL);
	else
		return (str + i);
}
