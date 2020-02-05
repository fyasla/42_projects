/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:37:08 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/05 14:50:37 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define MAX_OBJS 10
# define MAX_CAMS 5
# define MAX_LIGHTS 5

# include <math.h>
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"
# include "../libs/ft_printf/inc/ft_printf.h"
# include "structures.h"
# include "parsing.h"

double	to_rad(double deg);
t_vec3	mat_vec(t_mat33 mat, t_vec3 vec);
t_mat33	prod_mat(t_mat33 a, t_mat33 b);

t_vec3	vec(double x, double y, double z);
t_mat33	mat_rot_x(t_vec3 axe);
t_mat33	mat_rot_y(t_vec3 axe);
t_mat33	mat_rot_z(t_vec3 axe);
t_mat33	mat_rot(t_vec3 axe);

t_vec3	cam_to_world(t_vec3 cam_crd, t_cam cam);
t_vec3	rstr_to_cam(t_pix pix, t_scene *scene, int cam);
t_vec3	cam_to_world(t_vec3 cam_crd, t_cam cam);
t_vec3	mat_vec(t_mat33 mat, t_vec3 vec);

double	scal_prod(t_vec3 u, t_vec3 v);
t_vec3	vec_sum(t_vec3 u, t_vec3 v);
t_vec3	mul_vec(double k, t_vec3 u);
double	vec_norme(t_vec3 u);
t_vec3	normalize_vec(t_vec3 u);

int		pix_col(t_pix pix, t_scene *scene, int cam);

int		draw(t_win *win, t_scene *scene_ptr, int cam);

#endif
