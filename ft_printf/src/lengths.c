/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:06:19 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/12 19:27:32 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_in(char c, char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (1);
	}
	return (0);
}

int		ft_fs_len(char *start)
{
	int	len;

	len = 0;
	if (!start)
		return (-1);
	while (start[len])
	{
		if (ft_is_in(start[len], "cspdiuxX%"))
			return (len);
		len++;
	}
	return (-2);
}
