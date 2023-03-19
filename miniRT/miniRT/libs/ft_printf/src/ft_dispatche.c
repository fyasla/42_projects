/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatche.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 08:45:07 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/28 16:44:17 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		manage_conv(const char *format, va_list ap, int *i, int *count)
{
	char		*cs_str;
	t_conv_spec	conv_spec;
	t_conv_spec	*cs;

	cs = &conv_spec;
	cs->flag = 'D';
	cs->width = 0;
	cs->prec = -2;
	cs->type = 'D';
	if (!(cs_str = extract_cs(format, i, "cspdiuxX%")))
		return (-1);
	cs_parse(cs, cs_str, ap);
	*count += ft_dispatche(cs, ap);
	free(cs_str);
	return (0);
}

int		ft_dispatche(t_conv_spec *cs, va_list ap)
{
	char	cs_type;

	cs_type = cs->type;
	if (cs_type == 'c')
		return (ft_write_c(cs, ap));
	if (cs_type == 's')
		return (ft_write_s(cs, ap));
	if (cs_type == 'p')
		return (ft_write_p(cs, ap));
	if (cs_type == 'd' || cs_type == 'i')
		return (ft_write_id(cs, ap));
	if (cs_type == 'u')
		return (ft_write_u(cs, ap));
	if (cs_type == 'x')
		return (ft_write_x(cs, ap));
	if (cs_type == 'X')
		return (ft_write_xmaj(cs, ap));
	if (cs_type == '%')
		return (ft_write_pc(cs));
	write(1, "ERROR", 5);
	return (0);
}
