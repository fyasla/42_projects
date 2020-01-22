/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:37:08 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/22 13:42:49 by fbougama         ###   ########.fr       */
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

int		ft_isspace(char c);
int		ft_atof(char *str);
int		ft_atov(char *str);
t_color	vec3tocol(t_vec3 v);
void	skip_whitspaces(char *str, int *i);

//map_parse.c
t_scene	*map_parse(int map_fd);
int		line_parse(char *line, int *cpt_ptr, t_scene *scene_ptr);

//parse_1.c
int	parse_r(char *line, t_scene *scene_ptr);
int	parse_a(char *line, t_scene *scene_ptr);

//vectors.c
double	scal_prod(t_vec3 u, t_vec3 v);
t_vec3	vec_sum(t_vec3 u, t_vec3 v);
t_vec3	mul_vec(double k, t_vec3 u);
double	vec_norme(t_vec3 u);
t_vec3	normalized_vec(t_vec3 u);
#endif
