/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:08:51 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/07 16:38:27 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	int					i;

	i = 0;
	str1 = s1;
	str2 = s2;
	while (str1[i] == str2[i])
		i++;
	return (str2[i] - str1[i]);
}
