/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 19:50:21 by faysal            #+#    #+#             */
/*   Updated: 2021/08/18 17:39:29 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*sort(t_stacks *stacks, char *inst_list)
{
	int		stack_l;

	// while (!(is_ok(stacks)))
	// {
	// 	inst = chose_inst(stacks);
	// 	add_inst(inst, inst_list);
	// }
	stack_l = stack_length(stacks ->a);
	if (stack_l == 0 || stack_l == 1)
		return (inst_list);
	if (stack_l == 2)
		return (sort_2(stacks, inst_list));
	inst_list = refactor(inst_list);
	return (inst_list);
}

char	*refactor(char *inst_list)
{
	return (inst_list);
}

char	*add_inst(char *inst, char *inst_list)
{
	char	*new_list;

	if (!(new_list = malloc((ft_strlen(inst_list) + ft_strlen(inst) + 1) * sizeof(char))))
		return (NULL);
	ft_bzero(new_list, ft_strlen(inst_list) + ft_strlen(inst) + 1);
	ft_strlcpy(new_list, inst_list, ft_strlen(inst_list) + 1);
	ft_strlcat(new_list, inst, ft_strlen(new_list) + ft_strlen(inst) + 1);
	free (inst_list);
	return (new_list);
}

char	*sort_2(t_stacks *stacks, char *inst_list)
{
	if (!is_sorted(stacks->a))
		inst_list = add_inst("sa\n", inst_list);
	return (inst_list);
}
