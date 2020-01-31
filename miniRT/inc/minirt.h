/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:37:08 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 17:13:16 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//global variables
# define MAX_OBJS 10
# define MAX_CAMS 5
# define MAX_LIGHTS 5

# define POSSIBLE_IDS ""

//includes
# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"
# include "structures.h"
# include "../libs/ft_printf/inc/ft_printf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//parsing.utils.c

int		ft_isspace(char c);
double	ft_atof(char *str);
t_vec3	ft_atov(char *str);
t_color	vec3tocol(t_vec3 v);
int		skip_whitespaces(char *str, int *i);

//parsing_utils2.c
int		skip_numbers(char *str, int *i);
int		skip_signs(char *str, int *i);
int		skip_int(char *str, int *i);
int		skip_float(char *str, int *i);
int		skip_vector(char *str, int *i);

//parsing_utils3.c

int	ft_atoi(char *str);

//map_parse.c
t_scene	*map_parse(int map_fd);
int		line_parse(char *line, int *cpt, t_scene *scene_ptr);

//parse_1.c
int		parse_r(char *line, t_scene *scene_ptr);
int		parse_a(char *line, t_scene *scene_ptr);
int		parse_c(char *line, int *cpt, t_scene *scene_ptr);
int		parse_l(char *line, int *cpt, t_scene *scene_ptr);
int		parse_sp(char *line, int cpt[3], t_scene *scene_ptr);

//parse_2.c
int		parse_pl(char *line, int cpt[3], t_scene *scene_ptr);
int		parse_sq(char *line, int cpt[3], t_scene *scene_ptr);
int		parse_cy(char *line, int cpt[3], t_scene *scene_ptr);
int		parse_tr(char *line, int cpt[3], t_scene *scene_ptr);

//vectors.c
double	scal_prod(t_vec3 u, t_vec3 v);
t_vec3	vec_sum(t_vec3 u, t_vec3 v);
t_vec3	mul_vec(double k, t_vec3 u);
double	vec_norme(t_vec3 u);
t_vec3	normalize_vec(t_vec3 u);

//initate_scene.c

void	initiate_obj(t_obj *object);
void	initiate_cam(t_cam *camera);
void	initiate_light(t_light *light);
void	scene_initiate(t_scene *scene_ptr);
#endif
