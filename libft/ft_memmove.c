/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:47:08 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/07 15:31:53 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;
	int			i;
	char		*end_s;
	char		*end_d;

	i = 0;
	end_s = s + len - 1;
	end_d = d + len - 1;
	if (d < s)
	{
		while (i++ < len)
			d[i] = s[i];
	}
	else
	{
		while (len--)
			*end_d-- = *end_s--;
	}
	return (dst);
}
