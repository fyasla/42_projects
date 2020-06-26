/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:41:42 by faysal            #+#    #+#             */
/*   Updated: 2020/06/26 17:29:57 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int				gen(t_scene *s)
{
	int				h;
	int				w;
	unsigned char	im[s->resy][s->resx][3];
	t_pix			p;

	p.x = 0;
	h = s->resy;
	w = s->resx;
	while (p.x < w)
	{
		p.y = 0;
		while (p.y < h)
		{
			im[h - 1 - p.y][p.x][2] = (unsigned char)pix_col(p, s, s->cam).r;
			im[h - 1 - p.y][p.x][1] = (unsigned char)pix_col(p, s, s->cam).g;
			im[h - 1 - p.y][p.x][0] = (unsigned char)pix_col(p, s, s->cam).b;
			p.y++;
		}
		p.x++;
	}
	genbmpim((unsigned char *)im, h, w, "bitmapImage.bmp");
	return (0);
}

void			genbmpim(unsigned char *image, int h, int w, char *imgfn)
{
	unsigned char	padding[3];
	int				padds;
	int				imgf;
	int				i;

	padding[0] = 0;
	padding[1] = 0;
	padding[2] = 0;
	padds = (4 - (w * 3) % 4) % 4;
	imgf = open(imgfn, O_CREAT | O_WRONLY, 0777);
	write(imgf, createbmpfh(h, w, padds), 14);
	write(imgf, createbmpih(h, w), 40);
	i = 0;
	while (i < h)
	{
		write(imgf, image + (i * w * 3), 3 * w);
		write(imgf, padding, padds);
		i++;
	}
	close(imgf);
}

unsigned char	*createbmpfh(int h, int w, int padds)
{
	int						files;
	static unsigned char	fileh[14];
	int						i;

	files = 14 + 40 + (3 * w + padds) * h;
	i = 0;
	while (i < 14)
		fileh[i++] = 0;
	fileh[0] = (unsigned char)('B');
	fileh[1] = (unsigned char)('M');
	fileh[2] = (unsigned char)(files);
	fileh[3] = (unsigned char)(files >> 8);
	fileh[4] = (unsigned char)(files >> 16);
	fileh[5] = (unsigned char)(files >> 24);
	fileh[10] = (unsigned char)(14 + 40);
	return (fileh);
}

unsigned char	*createbmpih(int h, int w)
{
	static unsigned char	infoh[40];
	int						i;

	i = 0;
	while (i < 40)
		infoh[i++] = 0;
	infoh[0] = (unsigned char)(40);
	infoh[4] = (unsigned char)(w);
	infoh[5] = (unsigned char)(w >> 8);
	infoh[6] = (unsigned char)(w >> 16);
	infoh[7] = (unsigned char)(w >> 24);
	infoh[8] = (unsigned char)(h);
	infoh[9] = (unsigned char)(h >> 8);
	infoh[10] = (unsigned char)(h >> 16);
	infoh[11] = (unsigned char)(h >> 24);
	infoh[12] = (unsigned char)(1);
	infoh[14] = (unsigned char)(3 * 8);
	return (infoh);
}
