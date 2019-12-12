/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:15:27 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/12 19:02:57 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "inc/ft_printf.h"

#define TEST_TEMPLATE(...) 	printf("ft_printf ||"); fflush(NULL);\
							ret = ft_printf(__VA_ARGS__);\
							printf("|| Retour : %d\n", ret); fflush(NULL);\
							printf("PRINTF    ||");\
							ret = printf(__VA_ARGS__);\
							printf("|| Retour : %d\n\n", ret);

int	main(int ac, char **av)
{
	(void)ac;
	int ret;

	// -- without % --
	if (atoi(av[1]) == 100 || atoi(av[1]) == 0 )
	{
		printf("-- 0 : BAASIC STRINGS WITHOUT %% --\n\n");
		TEST_TEMPLATE("");
		TEST_TEMPLATE("\n");
		TEST_TEMPLATE("\t");
		TEST_TEMPLATE("	");
		TEST_TEMPLATE("test");
		TEST_TEMPLATE("TEST");
		TEST_TEMPLATE("321654/*..//\\\'\'\'\"ggllsgGYYGK &!@#$^&*(");
		printf("###############################################################################################\n\n");
	}
	// -- with % and simple conversion specifier --
	printf("blabla : %*d\n", 010, 50);
	return (0);
}