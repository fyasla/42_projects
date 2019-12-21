/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:11:05 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 20:14:25 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

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

int		unsigned_len(long unsigned addr , int len_base)
{
	int len;

	len = 2;
	if (addr == 0)
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
	int 			len;
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
