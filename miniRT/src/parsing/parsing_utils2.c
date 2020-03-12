/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:43:29 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/11 17:52:19 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	skip_numbers(char *str, int *i)
{
	while (str[*i] <= '9' && str[*i] >= '0')
		*i += 1;
	return (0);
}

int	skip_signs(char *str, int *i)
{
	while (str[*i] == '-' || str[*i] == '+')
		*i += 1;
	return (0);
}

int	skip_int(char *str, int *i)
{
	int	ret;

	ret = 0;
	ret += skip_whitespaces(str, i);
	ret += skip_signs(str, i);
	ret += skip_numbers(str, i);
	return (ret);
}

int	skip_float(char *str, int *i)
{
	int	ret;

	ret = 0;
	ret += skip_int(str, i);
	if (str[*i] == '.')
		*i += 1;
	ret += skip_numbers(str, i);
	return (ret);
}

int	skip_vector(char *str, int *i)
{
	int ret;

	ret = 0;
	ret += skip_float(str, i);
	if (str[*i] == ',')
		*i += 1;
	else
		return (-1);
	ret += skip_float(str, i);
	if (str[*i] == ',')
		*i += 1;
	else
		return (-1);
	ret += skip_float(str, i);
	return (ret);
}
