/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 12:27:27 by fbougama          #+#    #+#             */
/*   Updated: 2021/06/21 14:15:14 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0 && str[i] >= '0' && str[i] <= '9')
		i++;
	if (i < ft_strlen(str))
		return (0);
	else
		return (1);
}

int	check_arguments(int	arg_nb, char **arg_list)
{
	int	i;

	i = 0;
	while (i < arg_nb && is_integer(arg_list[i]))
		i++;
	if (i < arg_nb)
		return (0);
	else
		return (1);
}

int	main(int ac, char **av)
{	
	int	*a;
	int	*b;
	int	i;

	i = 1;
	if (!check_arguments(ac - 1, &av[1]))
	{
		printf("Error\n");
		return (1);
	}
	a = malloc(ac);
	b = malloc(ac);
	while (i < ac)
	{
		a[i] = ft_atoi(av[i]);
		printf("%d\n", a[i]);
		i++;
	}
	return (0);
}
