/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:23:50 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 21:22:16 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_write_c(t_conv_spec *cs, va_list ap)
{
	int		i;
	int		pos;
	char	c;

	c = va_arg(ap, int);
	pos = (cs->flag == '-') ? 0 : cs->width - 1;
	i = 0;
	if (cs->width > 1)
	{
		while (i < cs->width)
		{
			if (i == pos)
				write(1, &c, 1);
			else
				write(1, " ", 1);
			i++;
		}
		return (cs->width);
	}
	else
	{
		write(1, &c, 1);
		return (1);
	}
}
