/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:16:11 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/12 19:26:14 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int sg;
	int	res;

	sg = 1;
	res = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r' ||
	*str == '\v' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		sg = (44 - *str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = 10 * res + (*str - '0');
		str++;
	}
	return (sg * res);
}

int		ft_nb_dec(int n)
{
	int		dec;

	dec = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		dec += 1;
	while (n != 0)
	{
		n = n / 10;
		dec++;
	}
	return (dec);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				dec;
	unsigned int	abs_n;

	dec = ft_nb_dec(n);
	if (!(str = malloc((dec + 1))))
		return (NULL);
	abs_n = (n < 0) ? -n : n;
	if (n < 0)
		str[0] = '-';
	str += dec;
	*str-- = '\0';
	if (abs_n == 0)
		*str = '0';
	while (abs_n != 0)
	{
		*str = '0' + (abs_n % 10);
		abs_n = abs_n / 10;
		if (abs_n > 0 || n < 0)
			str--;
	}
	return (str);
}
