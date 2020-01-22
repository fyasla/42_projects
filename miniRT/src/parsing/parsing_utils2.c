/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:43:29 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/22 15:08:42 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	skip_numbers(char *str, int *i)
{
	while (line[*i] <= '9' && line[*i] >= '0')
		*i++;
}

void	skip_signs(char *str, int *i)
{
	while (line[*i] == '-' && line[*i] == '+')
		*i++;
}

void	skip_int(char *str, int *i)
{
	skip_whitespaces(str, i);
	skip_signs(str, i);
	skip_numbers(str, i);
}

void	skip_float(char *str, int *i)
{
	skip_int(str, i);
	if (str[*i] == '.')
		*i++;
	skip_numbers(str,i);
}

void	skip_vector(char *str, int *i)
{
	skip_float(str, i);
	if (str[*i] == ',')
		*i++;
	skip_float(str, i);
	if (str[*i] == ',')
		*i++;
	skip_float(str, i);
}