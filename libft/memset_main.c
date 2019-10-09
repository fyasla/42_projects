/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:08:31 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/09 12:31:53 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len);

int	main(int ac, char **av)
{
	(void)	ac;
	void	*ptr1;
	void	*ptr2;

	ptr1 = malloc(100);
	ptr2 = malloc(100);
	printf("ft_memset\n%d\n", ft_memset(ptr1, av[1][0], atoi(av[2])));
	printf("memset\n%d\n", memset(ptr2, av[1][0], atoi(av[2])));
	return (0);
}