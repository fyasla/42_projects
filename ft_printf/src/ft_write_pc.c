/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:31:29 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 23:40:31 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_write_pc(t_conv_spec *cs)
{
	int	ret;

	ret = 0;
	if (cs->flag == '0')
	{
		ret += ft_write_zeros_pc(cs);
		write(1, "%", 1);
		ret++;
	}
	else if (cs->flag == '-')
	{
		write(1, "%", 1);
		ret++;
		ret += ft_write_spaces_pc(cs);
	}
	else
	{
		ret += ft_write_spaces_pc(cs);
		write(1, "%", 1);
		ret++;
	}
	return (ret);
}

int		ft_write_zeros_pc(t_conv_spec *cs)
{
	int	i;

	i = 0;
	while (i < cs->width - 1)
	{
		write(1, "0", 1);
		i++;
	}
	return (i);
}

int		ft_write_spaces_pc(t_conv_spec *cs)
{
	int	i;

	i = 0;
	while (i < cs->width - 1)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}
