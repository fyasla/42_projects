/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:03:48 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/19 06:45:35 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	manage_conv(const char *format, va_list ap, int *i, int *count)
{
	char		*cs_str;
	t_conv_spec	*cs;

	if (!(cs = malloc (sizeof(t_conv_spec))))
		return;
	cs->flag = 'D';
	cs->width = 0;
	cs->prec = -1;
	cs->type = 'D';
	cs_str = extract_cs(format, i, "cspdiuxX%");
	cs_parse(cs, cs_str, ap);
	*count += ft_dispatche(cs, ap);
}
