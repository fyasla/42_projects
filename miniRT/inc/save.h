/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 16:06:50 by faysal            #+#    #+#             */
/*   Updated: 2020/06/24 18:44:34 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_H
# define SAVE_H

void genbmpim(unsigned char *image, int height, int width, char* imafn);
unsigned char* createbmpfh(int height, int width, int padsize);
unsigned char* createbmpih(int height, int width);
int gen(t_scene *scene);

#endif