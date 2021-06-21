/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:51:38 by fbougama          #+#    #+#             */
/*   Updated: 2021/06/21 15:55:29 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	str_is_inf(char *str, char *max)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] > max[i])
			return (0);
		i++;
	}
	return (1);
}

int	check_int_range(char *str)
{
	char	*max_int;
	char	*min_int;

	max_int = ft_strdup("2147483647");
	min_int = ft_strdup("-2147483648");
	if (ft_strlen(str) > ft_strlen(min_int))
		return (0);
	if (ft_strlen(str) == ft_strlen(min_int) && ft_isdigit(str[0]))
		return (0);
	if (ft_strlen(str) == ft_strlen(min_int) && str[0] == '+' && \
	!str_is_inf(str + sizeof(char), max_int))
		return (0);
	if (ft_strlen(str) == ft_strlen(min_int) && str[0] == '-' && \
	!str_is_inf(str + sizeof(char), min_int + sizeof(char)))
		return (0);
	if (ft_strlen(str) == ft_strlen(max_int) && ft_isdigit(str[0]) && \
	!str_is_inf(str, max_int))
		return (0);
	return (1);
}

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != 0 && ft_isdigit(str[i]))
		i++;
	if (i < ft_strlen(str))
		return (0);
	else
		return (check_int_range(str));
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

int	**initiate_stacks(int arg_nb, char **arg_list)
{
	int	*a;
	int	*b;
	int	**stacks;
	int	i;

	i = 0;
	a = malloc(arg_nb * sizeof (int));
	b = malloc(arg_nb * sizeof (int));
	stacks = malloc(2 * sizeof (int *));
	while (i < arg_nb)
	{
		a[i] = ft_atoi(arg_list[i]);
		printf("%d\n", a[i]);
		i++;
	}
	return (stacks);
}
