/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cs_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:59:42 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/19 14:07:38 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void	cs_flag(t_conv_spec *cs, char *cs_str, int *i)
{
	while (cs_str[*i] == '+' || cs_str[*i] == '-')
	{
		if (cs_str[*i] == '-')
			cs->flag = '-';
		*i += 1;
	}
	while (cs_str[*i] == '0')
	{
		if (cs->flag != '-')
			cs->flag = '0';
		*i += 1;
	}
}

void	cs_width(t_conv_spec *cs, char *cs_str, int *i)
{
	while(ft_isdigit(cs_str[*i]))
	{
		cs->width = cs->width * 10 + (cs_str[*i] - '0');
		*i += 1;
	}
}

void	cs_prec(t_conv_spec *cs, char *cs_str, int *i, va_list ap)
{
	if(cs_str[*i] == '.')
	{
		cs->prec = 0;
		*i += 1;
		if (!star_prec_handler(cs, cs_str, i, ap))
		{
			while(ft_isdigit(cs_str[*i]))
			{
				cs->prec = cs->prec * 10 + (cs_str[*i] - '0');
				*i += 1;
			}
		}
	}
}

void	cs_type(t_conv_spec *cs, char *cs_str, int *i)
{
	if(is_in(cs_str[*i], "cspdiuxX%"))
		cs->type = cs_str[*i];
}

void	cs_parse(t_conv_spec *cs, char *cs_str, va_list ap)
{
	int	i;

	i = 0;
	cs_flag(cs, cs_str, &i);
	if (!star_width_handler(cs, cs_str, &i, ap))
	{
		cs_flag(cs, cs_str, &i);
		cs_width(cs, cs_str, &i);
	}
	cs_prec(cs, cs_str, &i, ap);
	cs_type(cs, cs_str, &i);
}