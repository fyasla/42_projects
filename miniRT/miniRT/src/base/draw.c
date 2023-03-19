/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:13:06 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/12 17:14:04 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

char	*create_img(t_win *w, t_scene *scene)
{
	void	*img_ptr;
	char	*img;
	int		a;
	int		b;
	int		c;

	a = sizeof(unsigned int);
	b = scene->resx * sizeof(unsigned int);
	c = 1;
	if (!(img_ptr = mlx_new_image(w->mlx_p, scene->resx, scene->resy)))
		return (NULL);
	if (!(img = mlx_get_data_addr(img_ptr, &a, &b, &c)))
		return (NULL);
	w->img_p = img_ptr;
	return (img);
}

int		draw(t_win *w, t_scene *scene, char *img)
{
	int		sl;
	t_pix	p;
	int		uis;

	uis = sizeof(unsigned int);
	mlx_clear_window(w->mlx_p, w->win_p);
	img = create_img(w, scene);
	sl = scene->resx * uis;
	p.x = 0;
	while (p.x < scene->resx)
	{
		p.y = 0;
		while (p.y < scene->resy)
		{
			img[p.y * sl + p.x * uis] = (pix_col(p, scene, scene->cam).b);
			img[p.y * sl + p.x * uis + 1] = (pix_col(p, scene, scene->cam).g);
			img[p.y * sl + p.x * uis + 2] = (pix_col(p, scene, scene->cam).r);
			p.y++;
		}
		p.x++;
	}
	mlx_put_image_to_window(w->mlx_p, w->win_p, w->img_p, 0, 0);
	return (0);
}
