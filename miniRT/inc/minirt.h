/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:37:08 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/31 20:59:13 by fbougama         ###   ########.fr       */
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
t_vec3	cam_to_world(t_vec3 cam_crd, t_cam cam);

double	scal_prod(t_vec3 u, t_vec3 v);
t_vec3	vec_sum(t_vec3 u, t_vec3 v);
t_vec3	mul_vec(double k, t_vec3 u);
double	vec_norme(t_vec3 u);
t_vec3	normalize_vec(t_vec3 u);

int		pix_col(int	i, int j, t_scene *scene, int cam);

int		draw(t_win *win, t_scene *scene_ptr, int cam);

#endif
