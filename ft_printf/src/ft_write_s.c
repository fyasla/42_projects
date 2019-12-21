/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 01:16:29 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 18:53:25 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_write_s(t_conv_spec *cs, va_list ap)
{
	int		ret;
	char	*str;

	ret = 0;
	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	if (cs->flag == '-')
	{
		ret += write_s_prec(cs, str);
		ret += write_s_width(cs, str);
	}
	else
	{
		ret += write_s_width(cs, str);
		ret += write_s_prec(cs, str);
	}
	return (ret);
}

int		write_s_prec(t_conv_spec *cs, char *str)
{
	int	i;

	i = 0;
	while (str[i] && (i < cs->prec || cs->prec < 0))
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}

int		write_s_width(t_conv_spec *cs, char *str)
{
	int	i;
	int	len_s;

	i = 0;
	len_s = (ft_strlen(str) > cs->prec && cs->prec >= 0) ? cs->prec : ft_strlen(str);
	while (len_s + i < cs->width)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
