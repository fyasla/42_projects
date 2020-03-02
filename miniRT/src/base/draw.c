/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:13:06 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/02 13:08:30 by fbougama         ###   ########.fr       */
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

int		draw2(t_win *w, t_scene *scene, int cam)
{
	void	*img_ptr;
	char	*img;
	int		size_line;
	t_pix	pix;

	int		a;
	int		b;
	int		c;

	a = sizeof(unsigned int);
	b = scene->resx * sizeof(unsigned int);
	c = 1;

	if(!(img_ptr = mlx_new_image(w->mlx_p, scene->resx, scene->resy)))
		return (-1);

	if (!(img = mlx_get_data_addr(img_ptr, &a, &b,&c)))
		return (-1);

	size_line = scene->resx * sizeof(unsigned int);
	pix.x = 0;
	while (pix.x < scene->resx)
	{
		pix.y = 0;
		while (pix.y < scene->resy)
		{
			img[pix.y * size_line + pix.x * sizeof(unsigned int)] = (pix_col(pix, scene, cam).b);
			img[pix.y * size_line + pix.x * sizeof(unsigned int) + 1] = (pix_col(pix, scene, cam).g);
			img[pix.y * size_line + pix.x * sizeof(unsigned int) + 2] = (pix_col(pix, scene, cam).r);
			pix.y++;
		}
		pix.x++;
	}
	w->img_p = img_ptr;
	mlx_put_image_to_window(w->mlx_p, w->win_p, img_ptr, 0, 0);
	return (0);
}
