/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:08:40 by faysal            #+#    #+#             */
/*   Updated: 2021/09/28 20:59:19 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define RESX 	1300
# define RESY 	700
# define COL1	0x001337
# define COL2	0xbeeef3
# define MARGIN	0

# include "mlx.h"
# include "../lib/libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
	int		set;
}				t_point;

typedef struct s_window
{
	void	*mlx_p;
	void	*w_p;
	void	*img_p;
	char	*img;
}				t_window;

//conv_to_iso.c
t_point		p_to_iso(t_point p);
void		map_to_iso(t_point **map, char *filename, int r_nb);

//resize.c
t_point		p_min(t_point **map, int row_nb);
t_point		p_max(t_point **map, int row_nb);
void		resize_map(t_point **map, int row_nb, char *filename);
t_point		*resize_p(t_point p, t_point min, t_point max);

//plot_map.c
void		plot_right(t_point **map, int i, int j, t_window *win);
void		plot_low(t_point **map, int i, int j, t_window *win);
void		plot_map(t_point **map, char *filename, int r_nb, t_window *win);

//colors.c
int			set_color_p(t_point p, t_point **map, char *filename, int r_nb);
void		rgb(t_window *win, int x, int y, int rgb);
int			c_g(int color1, int color2, double pos);

//plot_line.c
void		update_coordinates(t_point *p, int x, int y, int z);
void		plot_line_low(t_point p0, t_point p1, t_window *window);
void		plot_line_high(t_point p0, t_point p1, t_window *window);
void		plot_line(t_point p0, t_point p1, t_window *window);

//parse_map.c
int			row_nb(char *filename);
int			count_words(char **tab);
int			line_length(int i, char *filename);
t_point		**map_alloc(char *filename);
t_point		coord(int x, int y, int z);

//parse_map2.c
void		fill_map(t_point **map, char *filename);
void		set_color_map(t_point **map, char *filename);
void		free_tab(char **tab);

//main.c
void		draw(t_window *win, char *filename);
void		win_init(t_window *win, char *filename);
int			main(int ac, char **av);

#endif
