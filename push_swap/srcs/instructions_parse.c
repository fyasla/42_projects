/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 15:41:12 by faysal            #+#    #+#             */
/*   Updated: 2021/08/13 16:28:55 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	instruction_error(void)
{
	printf("ERROR\n");
	return (-1);
}

int	check_instructions(void)
{
	ssize_t		ret;
	char		*buf;

	if (!(buf = malloc(BUFFER_SIZE * sizeof(char))))
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(0, &buf);
		if (ft_strncmp("sa", buf, 4) && ft_strncmp("sb", buf, 4)
			&& ft_strncmp("ss", buf, 4) && ft_strncmp("ra", buf, 4)
			&& ft_strncmp("rb", buf, 4) && ft_strncmp("rr", buf, 4)
			&& ft_strncmp("rra", buf, 4) && ft_strncmp("rrb", buf, 4)
			&& ft_strncmp("rrr", buf, 4) && ft_strncmp("pa", buf, 4)
			&& ft_strncmp("pb", buf, 4))
			return (instruction_error());
	}
	return (1);
}
