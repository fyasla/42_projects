/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:15:27 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/19 13:21:07 by fbougama         ###   ########.fr       */
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
							printf("|| Retour : %d\n\n", ret); fflush(NULL);

int	main(int ac, char **av)
{
	(void)ac;
	//(void)av;
	int ret;

	char str[15] = "abcdefghijklmn";
	char c = 'P';
	//-- without % --
	if (atoi(av[1]) == 100 || atoi(av[1]) == 0 )
	{
		printf("\t\t\t-- 0 : BASIC STRINGS WITHOUT %% --\n\n"); fflush(NULL);
		TEST_TEMPLATE("");
		TEST_TEMPLATE("\n");
		TEST_TEMPLATE("\t");
		TEST_TEMPLATE("	");
		TEST_TEMPLATE("test");
		TEST_TEMPLATE("TEST");
		TEST_TEMPLATE("321654/*..//\\\'\'\'\"ggllsgGYYGK &!^@#$^&*(");
		printf("###############################################################################################\n\n"); fflush(NULL);
	}

	// -- with %c --
	if (atoi(av[1]) == 100 || atoi(av[1]) == 1 )
	{
		printf("\t\t\t--  1 : BASIC STRINGS WITH %%c --\n\n"); fflush(NULL);
		TEST_TEMPLATE("%c", 0);
		TEST_TEMPLATE("%c", c);
		TEST_TEMPLATE("On s'amuse bien %c", '!');
		TEST_TEMPLATE("Avec deux : %c et %c", '1', '2');
		TEST_TEMPLATE("%c%c%c%c%c%c%c", '\t', 'p', 'r', 'i', 'n', 't', 1);

		printf("\n\t\t\t-- %%c with widths --\n\n"); fflush(NULL);
		TEST_TEMPLATE("%1c", '1');
		TEST_TEMPLATE("%2c", '2');
		TEST_TEMPLATE("%3c", '3');
		TEST_TEMPLATE("%100c", 'C');
		TEST_TEMPLATE("BLABLA %10c BLA%2c", 0, 6);
		TEST_TEMPLATE("hello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0);
		TEST_TEMPLATE("%-*c", 5,'O');
		TEST_TEMPLATE("%*c", 0,'Z');
		TEST_TEMPLATE("%*c", 50,'Z');
		TEST_TEMPLATE("%*c", -5,'Z');
		TEST_TEMPLATE("blabla : %-1.*s", 5, str);
		printf("###############################################################################################\n\n"); fflush(NULL);

	}
	// -- with %s --
	if (atoi(av[1]) == 100 || atoi(av[1]) == 2 )
	{
		printf("\t\t\t--  1 : STRINGS WITH %%s --\n\n"); fflush(NULL);
		TEST_TEMPLATE("blabla : %-1.*s", 5, str);
		TEST_TEMPLATE("blabla : %s", str);
		TEST_TEMPLATE("blabla : %-1.*s", 5, str);
		TEST_TEMPLATE("blabla : %-1.*s", 5, str);
		TEST_TEMPLATE("blabla : %-1.*s", 5, str);
		TEST_TEMPLATE("blabla : %-1.*s", 5, str);
	}
	return (0);
}