/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:22:57 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/22 00:29:10 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putnbr_base(long unsigned int n, char *base, int *ret)
{
	int	b_len;

	b_len = ft_strlen(base);
	if (n < b_len)
	{
		write(1, base + n, 1);
		*ret += 1;
	}
	else
	{
		ft_putnbr_base(n / b_len, base, ret);
		write(1, base + (n % b_len), 1);
		*ret += 1;
	}
}

int		addr_len(long unsigned addr, int len_base, t_conv_spec *cs)
{
	int len;

	len = 2;
	if (addr == 0 && cs->prec < 0)
		return (3);
	while (addr != 0)
	{
		addr = addr / len_base;
		len++;
	}
	return (len);
}

int		nb_len(int n, int len_base)
{
	int				len;
	unsigned int	abs_n;

	len = (n < 0) ? 1 : 0;
	abs_n = (n < 0) ? -n : n;
	if (abs_n == 0)
		return (1);
	while (abs_n != 0)
	{
		abs_n = abs_n / len_base;
		len++;
	}
	return (len);
}

int		uns_len(unsigned int n, int len_base)
{
	int				len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / len_base;
		len++;
	}
	return (len);
}
