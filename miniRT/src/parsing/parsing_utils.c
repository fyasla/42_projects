/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:12:33 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/21 15:33:00 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_atoi(char *str)
{
	int i;
	int n;
	int signe;

	i = 0;
	n = 0;
	signe = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (signe * n);
}

double	ft_atof(char *str)
{
	int		i;
	double	int_part;
	double	dec_part;
	int		signe;

	i = 0;
	signe = (str[i] == '-') ? -1 : 1;
	int_part = (double)ft_atoi(str);

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
		i++;
	if (str[i] == '.')
		i++;
	dec_part = (double)ft_atoi(str + i);
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		dec_part = dec_part / 10;
		i++;
	}
	return (int_part + signe * dec_part);	
}

# include <stdio.h>
int		main(int ac, char **av)
{
	(void)ac;

	printf("Resultat : %f\n", ft_atof(av[1]));
	return (0);
}