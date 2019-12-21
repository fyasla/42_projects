/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:46:54 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 21:20:31 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		cs_len(const char *str, char *conv_types)
{
	int	i;

	i = 0;
	while (str[i] && !is_in(str[i], conv_types))
		i++;
	i++;
	return (i);
}

char	*extract_cs(const char *format, int *i, char *conv_types)
{
	char	*cs_str;
	int		j;
	int		len;

	j = 0;
	len = cs_len(format + *i + 1, conv_types);
	if (!(cs_str = malloc(len + 1)))
		return (NULL);
	while (j < len)
	{
		cs_str[j] = format[j + *i + 1];
		j++;
	}
	*i += len + 1;
	cs_str[j] = '\0';
	return (cs_str);
}

int		star_width_handler(t_conv_spec *cs, char *cs_str, int *i, va_list ap)
{
	int	star;

	if (cs_str[*i] == '*')
	{
		star = va_arg(ap, int);
		if (star < 0)
		{
			cs->flag = '-';
			cs->width = -star;
		}
		else if (star == 0)
			cs->width = 0;
		else
			cs->width = star;
		*i += 1;
		return (1);
	}
	return (0);
}

int		star_prec_handler(t_conv_spec *cs, char *cs_str, int *i, va_list ap)
{
	if (cs_str[*i] == '*')
	{
		cs->prec = va_arg(ap, int);
		*i += 1;
		return (1);
	}
	return (0);
}
