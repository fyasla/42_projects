/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:02:59 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 21:13:33 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_write_id(t_conv_spec *cs, va_list ap)
{
	int				n;
	int				ret;

	ret = 0;
	n = va_arg(ap, int);
	if (cs->flag != '-')
		ret += ft_write_id_spaces(cs, n);
	ret += ft_write_id_minus(cs, n);
	ret += ft_write_id_zeros(cs, n);
	ret += ft_write_id_abs(cs, n);
	if (cs->flag == '-')
		ret += ft_write_id_spaces(cs, n);
	return (ret);
}

int		ft_write_id_spaces(t_conv_spec *cs, int n)
{
	int				nb_spaces;
	int				already_w;
	int				prec;
	int				i;

	prec = (n < 0) ? cs->prec +1 : cs->prec;
	already_w = (prec < nb_len(n, 10)) ? nb_len(n, 10) : prec;
	if (n == 0 && cs->prec == 0)
		already_w = 0;
	if (cs->flag == '0' && (cs->width < prec || prec < 0))
		return (0);
	i = 0;
	while (i < cs->width - already_w)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		ft_write_id_zeros(t_conv_spec *cs, int n)
{
	int				i;
	unsigned int	abs;

	abs = (n < 0) ? -n : n;
	i = 0;
	while (i < cs->prec - nb_len(abs, 10))
	{
		write(1, "0", 1);
		i++;
	}
	while (cs->prec < 0 && cs->flag == '0' && i + nb_len(n, 10) < cs->width)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int		ft_write_id_minus(t_conv_spec *cs, int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		return (1);
	}
	else
		return (0);
}

int		ft_write_id_abs(t_conv_spec *cs, int n)
{
	int				i;
	unsigned int	abs;

	abs = (n < 0) ? -n : n;
	i = 0;
	if (n != 0 || cs->prec != 0)
		ft_putnbr_base(abs, "0123456789", &i);
	return (i);
}
