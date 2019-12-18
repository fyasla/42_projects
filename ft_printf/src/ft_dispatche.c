/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatche.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 08:45:07 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/18 22:34:05 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_dispatche(t_conv_spec *cs, va_list ap)
{
	char	cs_type;

	cs_type = cs->type;
	if (cs_type == 'c')
		return (ft_write_c(cs, ap));
	// if (cs_type == 's')
	// 	return (ft_write_s(cs, ap));
	// if (cs_type == 'p')
	// 	return (ft_write_p(cs, ap));
	// if (cs_type == 'd')
	// 	return (ft_write_d(cs, ap));
	// if (cs_type == 'i')
	// 	return (ft_write_i(cs, ap));
	// if (cs_type == 'u')
	// 	return (ft_write_u(cs, ap));
	// if (cs_type == 'x')
	// 	return (ft_write_x(cs, ap));
	// if (cs_type == 'X')
	// 	return (ft_write_X(cs, ap));
	// if (cs_type == '%')
	// 	return (ft_write_pc(cs, ap));
	write(1, "ERROR", 5);
	return (0);
}
