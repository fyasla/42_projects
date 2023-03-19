/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:11:06 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 23:11:07 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_write_x(t_conv_spec *cs, va_list ap)
{
	int				n;
	int				ret;

	ret = 0;
	n = va_arg(ap, unsigned int);
	if (cs->flag != '-')
		ret += ft_write_x_spaces(cs, n);
	ret += ft_write_x_zeros(cs, n);
	ret += ft_write_x_abs(cs, n);
	if (cs->flag == '-')
		ret += ft_write_x_spaces(cs, n);
	return (ret);
}

int		ft_write_x_spaces(t_conv_spec *cs, unsigned int n)
{
	int				nb_spaces;
	int				already_w;
	int				i;

	already_w = (cs->prec < uns_len(n, 16)) ? uns_len(n, 16) : cs->prec;
	if (n == 0 && cs->prec == 0)
		already_w = 0;
	if (cs->flag == '0' && (cs->width < cs->prec || cs->prec < 0))
		return (0);
	i = 0;
	while (i < cs->width - already_w)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		ft_write_x_zeros(t_conv_spec *cs, unsigned int n)
{
	int	i;

	i = 0;
	while (i < cs->prec - uns_len(n, 16))
	{
		write(1, "0", 1);
		i++;
	}
	while (cs->prec < 0 && cs->flag == '0' && i + uns_len(n, 16) < cs->width)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int		ft_write_x_abs(t_conv_spec *cs, unsigned int n)
{
	int				i;

	i = 0;
	if (n != 0 || cs->prec != 0)
		ft_putnbr_base(n, "0123456789abcdef", &i);
	return (i);
}
