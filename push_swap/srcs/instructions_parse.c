/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:41:12 by faysal            #+#    #+#             */
/*   Updated: 2021/08/18 17:22:16 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ps_error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

int	end_of_input(char *buf)
{
	if (ft_strncmp("", buf, 1) == 0)
	{
		free(buf);
		return (1);
	}
	else
	{
		write(2, "Error\n", 6);
		free(buf);
		return (-1);
	}
}

int	instructions_parse(t_stacks *stacks)
{
	ssize_t		ret;
	char		*buf;

	if (!(buf = malloc(BUFFER_SIZE * sizeof(char))))
		return (-1);
	ret = get_next_line(0, &buf);
	while (ret >= 0)
	{
		if (ret == 0)
			return (end_of_input(buf));
		else if (ft_strncmp("sa", buf, 4) == 0)
			swap(stacks->a);
		else if (ft_strncmp("sb", buf, 4) == 0)
			swap(stacks->b);
		else if (ft_strncmp("ra", buf, 4) == 0)
			rotate(stacks->a);
		else if (ft_strncmp("rb", buf, 4) == 0)
			rotate(stacks->b);
		else if (ft_strncmp("rra", buf, 4) == 0)
			reverse_rotate(stacks->a);
		else if (ft_strncmp("rrb", buf, 4) == 0)
			reverse_rotate(stacks->b);
		else
			if (instructions_parse2(stacks, buf) == -1)
				return (-1);
		ret = get_next_line(0, &buf);
	}
	free(buf);
	return (1);
}

int	instructions_parse2(t_stacks *stacks, char *buf)
{
	if (ft_strncmp("ss", buf, 4) == 0)
	{
		swap(stacks->a);
		swap(stacks->b);
	}
	else if (ft_strncmp("rr", buf, 4) == 0)
	{
		rotate(stacks->a);
		rotate(stacks->b);
	}
	else if (ft_strncmp("rrr", buf, 4) == 0)
	{
		reverse_rotate(stacks->a);
		reverse_rotate(stacks->b);
	}
	else if (ft_strncmp("pa", buf, 4) == 0)
		push_ab(stacks->b, stacks->a);
	else if (ft_strncmp("pb", buf, 4) == 0)
		push_ab(stacks->a, stacks->b);
	else
	{
		free(buf);
		return (ps_error());
	}
	return (1);
}
