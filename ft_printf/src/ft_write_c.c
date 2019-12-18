/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:23:50 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/18 22:33:36 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_write_c(t_conv_spec *cs, va_list ap)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	if (cs->flag == '0')
	{
		write(1, "ERROR", 5);
		return (-1);
	}
	if (cs->flag == '-')
		pos = cs->width - 1;
	if (cs->width > 1)
	{
		while (i < cs->width)
		{
			if (i == pos)
				write(1, va_arg(ap, int), 1);
			else
				write(1, ' ', 1);
		}
		return (cs->width);
	}
	else
	{
		write(1, va_arg(ap, int), 10);
		return (1);
	}
}
