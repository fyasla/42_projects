/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:18:15 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 17:17:40 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_write_addr(long unsigned int addr)
{
	int	ret;

	ret = 0;
	write(1, "0x", 2);
	ret += 2;
	ft_putnbr_base(addr, "0123456789abcdef", &ret);
	return (ret);
}

void	ft_write_spaces(int n)
{
	while (n--)
		write(1, " ", 1);
}

int		ft_write_p(t_conv_spec *cs, va_list ap)
{
	long unsigned int	addr;
	int					len_addr;
	int					i;
	int					ret;

	i = 0;
	addr = va_arg(ap, long unsigned int);
	len_addr = unsigned_len(addr, 16);
	if (cs->width > len_addr && cs->flag != '-')
		ft_write_spaces(cs->width - len_addr);
	ft_write_addr(addr);
	if (cs->width > len_addr && cs->flag == '-')
		ft_write_spaces(cs->width - len_addr);
	ret = (cs->width > len_addr) ? cs->width : len_addr;
	return (ret);
}
