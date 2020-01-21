/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:37:08 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/21 16:51:47 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//global variables
# define MAX_OBJS 100
# define MAX_CAMS 10
# define MAX_LIGHTS 20

# define POSSIBLE_IDS ""

//includes
# include "get_next_line.h"
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "structures.h"
# include "../libs/ft_printf/inc/ft_printf.h"

//parsing.utils.c

int		ft_atof(char *str);
int		ft_atov(char *str);

//map_parse.c

//vectors.c
double	scal_prod(t_vec3 u, t_vec3 v);
t_vec3	vec_sum(t_vec3 u, t_vec3 v);
t_vec3	mul_vec(double k, t_vec3 u);
double	vec_norme(t_vec3 u);
t_vec3	normalized_vec(t_vec3 u);
#endif
