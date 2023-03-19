/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_xmaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:13:44 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 23:15:39 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_write_xmaj(t_conv_spec *cs, va_list ap)
{
	int				n;
	int				ret;

	ret = 0;
	n = va_arg(ap, unsigned int);
	if (cs->flag != '-')
		ret += ft_write_x_spaces(cs, n);
	ret += ft_write_x_zeros(cs, n);
	ret += ft_write_xmaj_abs(cs, n);
	if (cs->flag == '-')
		ret += ft_write_x_spaces(cs, n);
	return (ret);
}

int		ft_write_xmaj_abs(t_conv_spec *cs, unsigned int n)
{
	int				i;

	i = 0;
	if (n != 0 || cs->prec != 0)
		ft_putnbr_base(n, "0123456789ABCDEF", &i);
	return (i);
}
