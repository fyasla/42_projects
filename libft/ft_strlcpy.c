/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:11:24 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/08 12:24:09 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t ft_strlen(char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	int	dst_len;

	dst_len = ft_strlen(dst);
}