/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:44:11 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/23 13:41:40 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	unsigned int	abs_n;

	dec = ft_nb_dec(n);
	if (!(str = malloc((dec + 1) * sizeof(char))))
		return (NULL);
	abs_n = n;
	if (n < 0)
	{
		*str = '-';
		abs_n = -n;
	}
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
