/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:44:11 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/16 11:51:35 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_nb_dec(int n)
{
	int		n2;
	int		dec;

	dec = 0;
	n2 = n;
	if (n == 0)
		return (1);
	while (n2 != 0)
	{
		n2 = n2 / 10;
		dec++;
	}
	if (n < 0)
		dec += 1;
	return (dec);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				dec;

	if (n == -2147483648)
		return ("-2147483648");
	dec = ft_nb_dec(n);
	if (!(str = malloc((dec + 1) * sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		n = -n;
	}
	str += dec;
	*str-- = '\0';
	if (n == 0)
		*str-- = '0';
	while (n != 0)
	{
		*str-- = '0' + (n % 10);
		n = n / 10;
	}
	if (*str == '-')
		return (str);
	return (str + 1);
}
