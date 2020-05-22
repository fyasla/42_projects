/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:37:43 by fbougama          #+#    #+#             */
/*   Updated: 2020/05/21 16:06:45 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_win
{
	void		*mlx_p;
	void		*win_p;
	void		*img_p;
	void		*scene;
	char		*img;
}				t_win;

typedef struct	s_pix
{
	int		x;
	int		y;
}				t_pix;

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct	s_mat33
{
	t_vec3	v0;
	t_vec3	v1;
	t_vec3	v2;
}				t_mat33;

typedef	struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_obj
{
	char	type[3];
	t_vec3	vec0;
	t_vec3	vec1;
	t_vec3	vec2;
	double	float0;
	double	float1;
	t_color	color;
}				t_obj;

typedef struct	s_ray
{
	t_vec3	start;
	t_vec3	dir;
	t_obj	clst;
	double	t;
}				t_ray;

typedef struct	s_cam
{
	t_vec3	pos;
	t_vec3	ori;
	double	fov;
}				t_cam;

typedef struct	s_light
{
	t_vec3	pos;
	double	lum_rat;
	t_color	color;
}				t_light;

typedef	struct	s_scene
{
	int		cpt[3];
	int		cam;
	t_obj	objects[MAX_OBJS];
	t_cam	cameras[MAX_CAMS];
	t_light	lights[MAX_LIGHTS];
	int		resx;
	int		resy;
	t_light	amb_light;
}				t_scene;

#endif
