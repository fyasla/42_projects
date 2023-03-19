/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:18:15 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/22 00:29:32 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_write_addr(long unsigned int addr, t_conv_spec *cs)
{
	int	ret;

	ret = 0;
	write(1, "0x", 2);
	ret += 2;
	if (addr || cs->prec < 0)
		ft_putnbr_base(addr, "0123456789abcdef", &ret);
	return (ret);
}

int		ft_write_spaces_p(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		ft_write_p(t_conv_spec *cs, va_list ap)
{
	long unsigned int	addr;
	int					len_addr;
	int					i;
	int					ret;

	ret = 0;
	i = 0;
	addr = va_arg(ap, long unsigned int);
	len_addr = addr_len(addr, 16, cs);
	if (cs->width > len_addr && cs->flag != '-')
		ret += ft_write_spaces_p(cs->width - len_addr);
	ret += ft_write_addr(addr, cs);
	if (cs->width > len_addr && cs->flag == '-')
		ret += ft_write_spaces_p(cs->width - len_addr);
	return (ret);
}
