/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:15:27 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 19:46:41 by fbougama         ###   ########.fr       */
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
		printf("###############################################################################################\n\n"); fflush(NULL);

	}
	// -- with %s --
	if (atoi(av[1]) == 100 || atoi(av[1]) == 2 )
	{
		printf("\t\t\t--  1 : STRINGS WITH %%s --\n\n"); fflush(NULL);
		TEST_TEMPLATE("blabla : %-1.*s", 5, str);
		TEST_TEMPLATE("blabla : %.10s", str);
		TEST_TEMPLATE("blabla : %-*.*s", 50,50, str);
		TEST_TEMPLATE("blabla : %-*.2s", 10, str);
		TEST_TEMPLATE("blabla : %35.37s", str);
		TEST_TEMPLATE("blabla : %-101.*s", 0, str);
		TEST_TEMPLATE("blabla : %-*.*s", 0, 0, str);
		TEST_TEMPLATE("blabla : %-*.*s", 0, 10, str);
		TEST_TEMPLATE("blabla : %*.*s", 0, 10, str);
		TEST_TEMPLATE("blabla : %-*.*s", -30, 1, str);
		TEST_TEMPLATE("blabla : %-*.*s", 0, 10, NULL);
		TEST_TEMPLATE("%s", "coco");
		TEST_TEMPLATE("blabla : %-1.*s", 5, str);
		TEST_TEMPLATE("%.2s", NULL);
		TEST_TEMPLATE("%10s", NULL);
		printf("###############################################################################################\n\n"); fflush(NULL);
	}
	// -- with %p --
	if (atoi(av[1]) == 100 || atoi(av[1]) == 3 )
	{
		printf("\t\t\t--  1 : STRINGS WITH %%p --\n\n"); fflush(NULL);
		TEST_TEMPLATE("blabla : %------19p", str);
		TEST_TEMPLATE("blabla : %19p", str);
		TEST_TEMPLATE("blabla : %p", str);
		TEST_TEMPLATE("blabla : %*p", -30, str);
		TEST_TEMPLATE("blabla : %*p", 0, str);
		TEST_TEMPLATE("blabla : %------*p", -50, str);
		TEST_TEMPLATE("blabla : %------*p", 30, str);
		TEST_TEMPLATE("blabla : %------*p", 30, NULL);
		printf("###############################################################################################\n\n"); fflush(NULL);
	}
	// -- with %d --
	if (atoi(av[1]) == 100 || atoi(av[1]) == 4 )
	{
		printf("\t\t\t--  1 : STRINGS WITH %%d --\n\n"); fflush(NULL);
		TEST_TEMPLATE("%d", 0);
		TEST_TEMPLATE("%d", -1);
		TEST_TEMPLATE("%d", 1);
		TEST_TEMPLATE("int min : %d", -2147483647);
		//TEST_TEMPLATE("int min : %d", -2147483648);// do not compile
		//TEST_TEMPLATE("int min -1: %d", -2147483649);
		//TEST_TEMPLATE("int min *10: %d", -21474836480);
		TEST_TEMPLATE("int max : %d", 2147483647);
		//TEST_TEMPLATE("int max +1: %d", 2147483648);
		//TEST_TEMPLATE("int max *10: %d", 21474836470);
		TEST_TEMPLATE("int min : %020d", -2147483647);
		//TEST_TEMPLATE("int min : %-0d", -2147483647);
		TEST_TEMPLATE("int min : %*d", 030, -2147483647);
		TEST_TEMPLATE("int min : %*d", -030, -2147483647);
		TEST_TEMPLATE("int min : %.20d", -2147483647);
		TEST_TEMPLATE("int min : %-.*d", 00, -2147483647);
		TEST_TEMPLATE("int min : %-.*d", 20, -2147483647);
		TEST_TEMPLATE("int min : %-.*d", -20, -2147483647);
		TEST_TEMPLATE("01.2: %01.*d", 2, 1);
		TEST_TEMPLATE("03.2 : %03.*d", 2, 1);
		TEST_TEMPLATE("-3.2 : %-3.*d", 2, 1);
		TEST_TEMPLATE("03.1 : %03.1d", -1);
		TEST_TEMPLATE("3 : %3d", 1);
		TEST_TEMPLATE("03.2 : %03.2d", 1);
		TEST_TEMPLATE("3.0 : %3.0d", 12);
		TEST_TEMPLATE("3.0 : %3.0d", 0);
		TEST_TEMPLATE(".0 : %.0d", 0);
		TEST_TEMPLATE(".1 : %.1d", 0);
		TEST_TEMPLATE(".3 : %.3d", 0);
		TEST_TEMPLATE(".0 : %.0d", -16);
		TEST_TEMPLATE(".0 : %.0d", 10);
		TEST_TEMPLATE(".1 : %.1d", 0);
		TEST_TEMPLATE(". : %.d", 0);
		TEST_TEMPLATE("62.1 : %.1d", 57);
		TEST_TEMPLATE("20.0 : %20.0d", 00);
		TEST_TEMPLATE("020.0 : %020.0d", 00);
		TEST_TEMPLATE(".1 : %.1d", -1);
		TEST_TEMPLATE(".2 : %.2d", -1);
		TEST_TEMPLATE(".3 : %.3d", -1);
		TEST_TEMPLATE("1 : %1d", -1);
		TEST_TEMPLATE("2 : %2d", -1);
		TEST_TEMPLATE("3 : %3d", -1);
		TEST_TEMPLATE("01 : %01d", -1);
		TEST_TEMPLATE("02 : %02d", -1);
		TEST_TEMPLATE("03 : %03d", -1);
		TEST_TEMPLATE("01.1 : %01.1d", -1);
		TEST_TEMPLATE("02.1 : %02.1d", -1);
		TEST_TEMPLATE("03.1 : %03.1d", -1);
		TEST_TEMPLATE("01.3 : %01.3d", -1);
		TEST_TEMPLATE("02.3 : %02.3d", -1);
		TEST_TEMPLATE("03.3 : %03.3d", -1);
		TEST_TEMPLATE("010.3 : %010.3d", -1);
		TEST_TEMPLATE("10.3 : %10.3d", -1);
		printf("###############################################################################################\n\n"); fflush(NULL);
	}
	return (0);
}