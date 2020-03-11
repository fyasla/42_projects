/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:13:06 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/11 15:30:55 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// int		draw(t_win *w, t_scene *scene, int cam)
// {
// 	t_pix	pix;

// 	pix.x = 0;
// 	while (pix.x < scene->resx)
// 	{
// 		pix.y = 0;
// 		while (pix.y < scene->resy)
// 		{
// 			mlx_pixel_put(w->mlx_p, w->win_p, pix.x, pix.y, pix_col(pix, scene, cam));
// 			pix.y++;
// 		}
// 		pix.x++;
// 	}
// 	return (0);
// }

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

	if(!(img_ptr = mlx_new_image(w->mlx_p, scene->resx, scene->resy)))
		return (NULL);

	if (!(img = mlx_get_data_addr(img_ptr, &a, &b,&c)))
		return (NULL);

	w->img_p = img_ptr;
	return (img);
}

int		draw2(t_win *w, t_scene *scene, char *img)
{
	int		size_line;
	t_pix	pix;

	mlx_clear_window(w->mlx_p, w->win_p);
	img = create_img(w, scene);
	size_line = scene->resx * sizeof(unsigned int);
	pix.x = 0;
	while (pix.x < scene->resx)
	{
		pix.y = 0;
		while (pix.y < scene->resy)
		{
			img[pix.y * size_line + pix.x * sizeof(unsigned int)] = (pix_col(pix, scene, scene->cam).b);
			img[pix.y * size_line + pix.x * sizeof(unsigned int) + 1] = (pix_col(pix, scene, scene->cam).g);
			img[pix.y * size_line + pix.x * sizeof(unsigned int) + 2] = (pix_col(pix, scene, scene->cam).r);
			pix.y++;
		}
		pix.x++;
	}
	mlx_put_image_to_window(w->mlx_p, w->win_p, w->img_p, 0, 0);
	return (0);
}
