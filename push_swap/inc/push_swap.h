/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:51:54 by fbougama          #+#    #+#             */
/*   Updated: 2021/08/13 19:24:06 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>//
#include "../libft/libft.h"

typedef struct	s_list2
{
	struct s_list2	*prev;
	int				content;
	struct s_list2	*next;
}				t_list2;

typedef struct	s_stacks
{
	t_list2	**a;
	t_list2	**b;
}				t_stacks;


t_list2	*ft_lst2new(int content);
void	ft_lst2addtop(t_list2 **bottom, t_list2 *new);
t_list2	*ft_lst2top(t_list2 **bottom);
void	ft_lst2deltop(t_list2 **bottom);

void	swap(t_list2 **bottom);
void	rotate(t_list2 **bottom);
void	reverse_rotate(t_list2 **bottom);
void	push_ab(t_list2 **a_bottom, t_list2 **b_bottom);
void	print_stack(t_list2 **bottom);

int	str_is_inf(char *str, char *max);
int	check_int_range(char *str);
int	is_integer(char *str);
int	check_arguments(int	arg_nb, char **arg_list);
int	check_duplicates(int *int_list, int int_nb);
t_stacks	*initiate_stacks(int arg_nb, char **arg_list);

int	is_sorted(t_list2 **bottom);
int is_empty(t_list2 **bottom);
int	is_ok(t_stacks *stacks);

int	instruction_error();
int	instructions_parse(t_stacks *stacks);
int	instructions_parse2(t_stacks *stacks, char *buf);


#endif