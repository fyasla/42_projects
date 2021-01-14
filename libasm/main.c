/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:09:05 by faysal            #+#    #+#             */
/*   Updated: 2021/01/14 18:12:42 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*str;
	(void)	ac;

	printf("\nac : %d\nstrlen :%d", strlen(av[1]), ft_strlen(av[1]));
	return (0);
}
