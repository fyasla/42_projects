/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:06:09 by faysal            #+#    #+#             */
/*   Updated: 2020/05/21 16:13:41 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/save.h"

/*
** see https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
*/

/*
** note: little endian
*/

static void	write_int(t_frame_saver *sv, unsigned int val)
{
	sv->buf[sv->index++] = val >> 0;
	sv->buf[sv->index++] = val >> 8;
	sv->buf[sv->index++] = val >> 16;
	sv->buf[sv->index++] = val >> 24;
}

/*
** file header
**
** "BM" (2o)
** file size (4o)
** null (2o)
** null (2o)
** 54,0,0,0 (4o)
*/

static void	write_file_header(t_state *s, t_frame_saver *sv)
{
	sv->buf[sv->index++] = 'B';
	sv->buf[sv->index++] = 'M';
	write_int(sv, sv->size);
	write_int(sv, 0x00000000);
	sv->buf[sv->index++] = 54;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
}

/*
** file info
**
** 40,0,0,0 (4o)
** width (4o)
** height (4o)
** 1,0 (2o)
** 24,0 (2o)
** null (24o)
*/

static void	write_file_info(t_state *s, t_frame_saver *sv)
{
	int i;

	sv->buf[sv->index++] = 40;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 0;
	write_int(sv, s->screen_sz.x);
	write_int(sv, s->screen_sz.y);
	sv->buf[sv->index++] = 1;
	sv->buf[sv->index++] = 0;
	sv->buf[sv->index++] = 24;
	sv->buf[sv->index++] = 0;
	i = 0;
	while (i < 24)
	{
		sv->buf[sv->index++] = 0;
		i++;
	}
}

/*
** body
**
** 1 pixel = 3o (0xBBGGRR)
** 1 row = w pixels + padding (0, 1, 2 or 3 for alignement)
*/

static void	write_body(t_state *s, t_frame_saver *sv)
{
	int x;
	int y;

	y = s->screen_sz.y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < s->screen_sz.x)
		{
			sv->buf[sv->index++] = s->screen[y * s->screen_sz.x + x] >> 0;
			sv->buf[sv->index++] = s->screen[y * s->screen_sz.x + x] >> 8;
			sv->buf[sv->index++] = s->screen[y * s->screen_sz.x + x] >> 16;
			x++;
		}
		x = 0;
		while (x < (4 - (s->screen_sz.x * 3) % 4) % 4)
		{
			sv->buf[sv->index++] = 0;
			x++;
		}
		y--;
	}
}

/*
** batch write
*/

t_err		save_first_frame(t_state *s, char *filename)
{
	int				fd;
	t_frame_saver	sv;

	render(s);
	sv = (t_frame_saver) { 0 };
	sv.size = 54 + 3 * s->screen_sz.x * s->screen_sz.y +
		((4 - (s->screen_sz.x * 3) % 4) % 4) * s->screen_sz.y;
	sv.buf = malloc(sv.size);
	if ((fd = open(filename, O_WRONLY | O_CREAT)) < 0)
		return (ERR_IO);
	write_file_header(s, &sv);
	write_file_info(s, &sv);
	write_body(s, &sv);
	write(fd, sv.buf, sv.size);
	close(fd);
	return (NULL);
}