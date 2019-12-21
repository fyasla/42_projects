/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatche.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 08:45:07 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 23:46:58 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	manage_conv(const char *format, va_list ap, int *i, int *count)
{
	char		*cs_str;
	t_conv_spec	*cs;

	if (!(cs = malloc(sizeof(t_conv_spec))))
		return ;
	cs->flag = 'D';
	cs->width = 0;
	cs->prec = -2;
	cs->type = 'D';
	cs_str = extract_cs(format, i, "cspdiuxX%");
	cs_parse(cs, cs_str, ap);
	*count += ft_dispatche(cs, ap);
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
