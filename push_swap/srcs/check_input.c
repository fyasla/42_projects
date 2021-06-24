/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:51:38 by fbougama          #+#    #+#             */
/*   Updated: 2021/06/24 03:39:03 by faysal           ###   ########.fr       */
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
	unsigned int	i;

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

t_stacks	*initiate_stacks(int arg_nb, char **arg_list)
{
	t_list2	**a_bottom;
	t_list2	**b_bottom;
	t_stacks *stacks;
	t_list2	*new;
	int	i;

	i = arg_nb - 1;
	if (!(a_bottom = malloc(sizeof (t_list2 *))))
		return (NULL);
	if (!(b_bottom = malloc(sizeof (t_list2 *))))
		return (NULL);
	if (!(stacks = malloc (sizeof(t_stacks ))))
		return (NULL);
	stacks->a = a_bottom;
	stacks->b = b_bottom;
	*a_bottom = NULL;
	*b_bottom = NULL;
	while (i >= 0)
	{
		if(!(new = ft_lst2new(ft_atoi(arg_list[i]))))
			return (NULL);
		ft_lst2addtop(stacks->a, new);
		i--;
	}
	return (stacks);
}
