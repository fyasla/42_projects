/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:11:58 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/12 17:57:32 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int		ft_isspace(char c);
double	ft_atof(char *str);
t_vec3	ft_atov(char *str);
t_color	vec3tocol(t_vec3 v);
int		skip_whitespaces(char *str, int *i);

int		skip_numbers(char *str, int *i);
int		skip_signs(char *str, int *i);
int		skip_int(char *str, int *i);
int		skip_float(char *str, int *i);
int		skip_vector(char *str, int *i);

int		ft_atoi(char *str);

t_scene	*map_parse(int map_fd);
int		line_parse(char *line, int *cpt, t_scene *scene_ptr);
int		line_parse2(char *line, int *cpt, t_scene *scene_ptr);

int		parse_r(char *line, t_scene *scene_ptr);
int		parse_a(char *line, t_scene *scene_ptr);
int		parse_c(char *line, int *cpt, t_scene *scene_ptr);
int		parse_l(char *line, int *cpt, t_scene *scene_ptr);
int		parse_sp(char *line, int cpt[3], t_scene *scene_ptr);

int		parse_pl(char *line, int cpt[3], t_scene *scene_ptr);
int		parse_sq(char *line, int cpt[3], t_scene *scene_ptr);
int		parse_cy(char *line, int cpt[3], t_scene *scene_ptr);
int		parse_tr(char *line, int cpt[3], t_scene *scene_ptr);

void	initiate_obj(t_obj *object);
void	initiate_cam(t_cam *camera);
void	initiate_light(t_light *light);
void	scene_initiate(t_scene *scene_ptr);

#endif
