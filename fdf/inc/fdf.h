/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:08:40 by faysal            #+#    #+#             */
/*   Updated: 2021/08/30 20:42:28 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
#include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_window;

//plot_line.c
void	plot_line_low(t_point p0, t_point p1, t_window window);
void	plot_line_high(t_point p0, t_point p1, t_window window);
void	plot_line(t_point p0, t_point p1, t_window window);

#endif