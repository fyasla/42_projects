/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:37:43 by fbougama          #+#    #+#             */
/*   Updated: 2020/02/05 14:14:05 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_win
{
	void		*mlx_p;
	void		*win_p;
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

typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}				t_ray;

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
	t_obj	objects[MAX_OBJS];
	t_cam	cameras[MAX_CAMS];
	t_light	lights[MAX_LIGHTS];
	int		resx;
	int		resy;
	t_light	amb_light;
}				t_scene;

// typedef struct	s_2dcoord
// {
// 	double	x;
// 	double	y;
// }				t_2dcoord;

// /*typedef	struct	s_mat33
// {
// 	t_3dcoord	c1;
// 	t_3dcoord	c2;
// 	t_3dcoord	c3;
// }*/

// typedef struct	s_obj
// {
// 	t_3dcoord	pos;
// 	t_3dcoord	ori;
// }

// typedef struct	s_cam
// {
// 	t_obj	obj;
// 	int		fov;
// }				t_cam;

#endif
