/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:10:50 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/23 13:42:24 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs;
	char			c;

	if (fd < 0)
		return ;
	abs = n;
	if (n < 0)
	{
		c = '-';
		write(fd, &c, sizeof(char));
		abs = -n;
	}
	if (abs < 10)
		c = abs + '0';
	else
	{
		ft_putnbr_fd(abs / 10, fd);
		c = abs % 10 + '0';
	}
	write(fd, &c, sizeof(char));
}
