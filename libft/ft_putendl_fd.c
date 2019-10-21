/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 13:47:43 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/19 11:44:55 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		write(fd, s, len * sizeof(char));
		write(fd, "\n", sizeof(char));
	}
}
