/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:02:59 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 18:44:29 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_write_id_prec(t_conv_spec *cs, unsigned int n)
{
	int	i;

	i = 0;
	while (i + unsigned_len(n, 10) < cs->prec )
	{
		write(1, "0", 1);
		i++;
	}
	ft_putnbr_base(n, "0123456789", &i);
	return (i);
}

int		ft_write_id_width(t_conv_spec *cs, unsigned int n)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	len = (cs->prec < unsigned_len(n, 10)) ? unsigned_len(n, 10) : cs->prec;
	c = (cs->flag == '0') ? '0' : ' ';
	while (i + len < cs->width)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int		ft_write_id(t_conv_spec	*cs, va_list ap)
{
	unsigned int	abs;
	int				n;
	int				prec;
	int				ret;

	ret = 0;
	n = va_arg(ap, int);
	if (n < 0)
	{
		write(1, " ", 1);
		cs->width -= 1;
		ret += 1;
	}
	abs = (n < 0) ? -n : n;
	prec = (n < 0) ? cs->prec + 1 : cs->prec;
	if (n == 0 && prec == 0)
		return (0);
	if (cs->flag == '-')
	{
		ret += ft_write_id_prec(cs, abs);
		ret += ft_write_id_width(cs, abs);
	}
	else
	{
		ret += ft_write_id_width(cs, abs);
		ret += ft_write_id_prec(cs, abs);
	}
	return (ret);
}
