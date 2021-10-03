/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:08:40 by faysal            #+#    #+#             */
/*   Updated: 2021/10/03 20:41:43 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef struct s_inc
{
	int	i;
	int	j;
}				t_inc;

typedef struct s_window
{
	void	*mlx_p;
	void	*w_p;
	void	*img_p;
	char	*img;
}				t_window;

typedef struct s_point
{
	double		x;
	double		y;
	double		z;
	int			color;
	int			set;
	t_window	win;
}				t_point;

//conv_to_iso.c
t_point		p_to_iso(t_point p);
void		map_to_iso(t_point **map, int r_nb, int *lls);
void		tab_line_free(char *line, char **split);
void		get_next_line_protect(int *fd, char **line);

//resize.c
t_point		p_min(t_point **map, int row_nb);
t_point		p_max(t_point **map, int row_nb);
void		resize_map(t_point **map, int row_nb, int *lls);
t_point		resize_p(t_point p, t_point min, t_point max);

//plot_map.c
void		plot_right(t_point **map, int i, int j, t_window *win);
void		plot_low(t_point **map, int i, int j, t_window *win);
void		plot_map(t_point **map, int r_nb, t_window *win, int *lls);
void		free_close(int fd, char *line);

//colors.c
int			set_color_p(t_point p, t_point **map, int r_nb);
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
int			*line_lengths(char *filename, int r_nb);
t_point		**map_alloc(int r_nb, int *lls);
t_point		coord(int x, int y, int z);

//parse_map2.c
void		fill_map(t_point **map, char *filename, int r_nb);
void		set_color_map(t_point **map, int r_nb);
void		free_tab(void **tab);
void		free_map(t_point **map);
void		split_loop(int *i, int *j, char ***split, t_point **map);

//main.c
t_point		**draw(t_window *win, char *filename);
t_point		**win_init(t_window *win, char *filename);
int			main(int ac, char **av);

//events.c
void		handle_events(t_window *win, t_point **map);
int			close2(t_point **map);
int			close3(char **split);
int			key_press(int key, void *param);
void		open_error(void);

#endif
