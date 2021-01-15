/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:09:05 by faysal            #+#    #+#             */
/*   Updated: 2021/01/16 00:21:14 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "inc/libasm.h"

int		main(int ac, char **av)
{
	(void)	ac;

	printf("ac : %ld\nstrlen :%ld\n", strlen(av[1]), ft_strlen(av[1]));
	return (0);
}
