/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:51:54 by fbougama          #+#    #+#             */
/*   Updated: 2021/06/21 15:55:46 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

int	str_is_inf(char *str, char *max);
int	check_int_range(char *str);
int	is_integer(char *str);
int	check_arguments(int	arg_nb, char **arg_list);
int	**initiate_stacks(int arg_nb, char **arg_list);

#endif