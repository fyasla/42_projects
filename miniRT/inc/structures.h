/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:37:43 by fbougama          #+#    #+#             */
/*   Updated: 2020/01/07 14:45:29 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_win;

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

typedef struct	s_obj
{
	char	*type;
	t_col	color;
}				t_obj;

typedef	struct	s_col
{
	int		R;
	int		G;
	int		B;
}				t_col;

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
