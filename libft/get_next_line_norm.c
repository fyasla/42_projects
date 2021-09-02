/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_norm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:11:58 by faysal            #+#    #+#             */
/*   Updated: 2021/09/02 18:14:27 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	rd_buff(char **buff, int *rd, int fd)
{
	*buff = ft_bzero2(buff, BUFFER_SIZE + 1);
	*rd = read(fd, buff, BUFFER_SIZE);
}
