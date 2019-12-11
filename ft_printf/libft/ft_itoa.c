/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:44:11 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/30 13:54:15 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_dec(int n)
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

char		*ft_itoa(int n)
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
