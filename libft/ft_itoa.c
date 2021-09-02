/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:44:11 by fbougama          #+#    #+#             */
/*   Updated: 2021/09/02 18:00:49 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nb_dec(int n)
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
	str = malloc((dec + 1) * sizeof(char));
	if (!str)
		return (NULL);
	abs_n = n;
	if (n < 0)
		*str = '-';
	if (n < 0)
		abs_n = -n;
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
