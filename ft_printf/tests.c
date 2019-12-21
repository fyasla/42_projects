/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:15:27 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/21 23:29:57 by fbougama         ###   ########.fr       */
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
	// -- with %d i --
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
	// -- with %u --
	if (atoi(av[1]) == 100 || atoi(av[1]) == 5 )
	{
		printf("\t\t\t--  1 : STRINGS WITH %%u --\n\n"); fflush(NULL);
		TEST_TEMPLATE("%u", 0);
		TEST_TEMPLATE("%u", -1);
		TEST_TEMPLATE("%u", 1);
		TEST_TEMPLATE("int min : %u", -2147483647);
		//TEST_TEMPLATE("int min : %u", -2147483648);// do not compile
		//TEST_TEMPLATE("int min -1: %u", -2147483649);
		//TEST_TEMPLATE("int min *10: %u", -21474836480);
		TEST_TEMPLATE("int max : %u", 2147483647);
		//TEST_TEMPLATE("int max +1: %u", 2147483648);
		//TEST_TEMPLATE("int max *10: %u", 21474836470);
		TEST_TEMPLATE("int min : %020u", -2147483647);
		//TEST_TEMPLATE("int min : %-0u", -2147483647);
		TEST_TEMPLATE("int min : %*u", 030, -2147483647);
		TEST_TEMPLATE("int min : %*u", -030, -2147483647);
		TEST_TEMPLATE("int min : %.20u", -2147483647);
		TEST_TEMPLATE("int min : %-.*u", 00, -2147483647);
		TEST_TEMPLATE("int min : %-.*u", 20, -2147483647);
		TEST_TEMPLATE("int min : %-.*u", -20, -2147483647);
		TEST_TEMPLATE("01.2: %01.*u", 2, 1);
		TEST_TEMPLATE("03.2 : %03.*u", 2, 1);
		TEST_TEMPLATE("-3.2 : %-3.*u", 2, 1);
		TEST_TEMPLATE("03.1 : %03.1u", -1);
		TEST_TEMPLATE("3 : %3u", 1);
		TEST_TEMPLATE("03.2 : %03.2u", 1);
		TEST_TEMPLATE("3.0 : %3.0u", 12);
		TEST_TEMPLATE("3.0 : %3.0u", 0);
		TEST_TEMPLATE(".0 : %.0u", 0);
		TEST_TEMPLATE(".1 : %.1u", 0);
		TEST_TEMPLATE(".3 : %.3u", 0);
		TEST_TEMPLATE(".0 : %.0u", -16);
		TEST_TEMPLATE(".0 : %.0u", 10);
		TEST_TEMPLATE(".1 : %.1u", 0);
		TEST_TEMPLATE(". : %.u", 0);
		TEST_TEMPLATE("62.1 : %.1u", 57);
		TEST_TEMPLATE("20.0 : %20.0u", 00);
		TEST_TEMPLATE("020.0 : %020.0u", 00);
		TEST_TEMPLATE(".1 : %.1u", -1);
		TEST_TEMPLATE(".2 : %.2u", -1);
		TEST_TEMPLATE(".3 : %.3u", -1);
		TEST_TEMPLATE("1 : %1u", -1);
		TEST_TEMPLATE("2 : %2u", -1);
		TEST_TEMPLATE("3 : %3u", -1);
		TEST_TEMPLATE("01 : %01u", -1);
		TEST_TEMPLATE("02 : %02u", -1);
		TEST_TEMPLATE("03 : %03u", -1);
		TEST_TEMPLATE("01.1 : %01.1u", -1);
		TEST_TEMPLATE("02.1 : %02.1u", -1);
		TEST_TEMPLATE("03.1 : %03.1u", -1);
		TEST_TEMPLATE("01.3 : %01.3u", -1);
		TEST_TEMPLATE("02.3 : %02.3u", -1);
		TEST_TEMPLATE("03.3 : %03.3u", -1);
		TEST_TEMPLATE("010.3 : %010.3u", -1);
		TEST_TEMPLATE("10.3 : %10.3u", -1);
		TEST_TEMPLATE("toto et %02u coco %-5u mimi", 19, (unsigned int)-20);
		printf("###############################################################################################\n\n"); fflush(NULL);
	}
		// -- with %x --
	if (atoi(av[1]) == 100 || atoi(av[1]) == 6 )
	{
		printf("\t\t\t--  1 : STRINGS WITH %%x --\n\n"); fflush(NULL);
		TEST_TEMPLATE("%x", 0);
		TEST_TEMPLATE("%x", -1);
		TEST_TEMPLATE("%x", 1);
		TEST_TEMPLATE("int min : %x", -2147483647);
		//TEST_TEMPLATE("int min : %x", -2147483648);// do not compile
		//TEST_TEMPLATE("int min -1: %x", -2147483649);
		//TEST_TEMPLATE("int min *10: %x", -21474836480);
		TEST_TEMPLATE("int max : %x", 2147483647);
		//TEST_TEMPLATE("int max +1: %x", 2147483648);
		//TEST_TEMPLATE("int max *10: %x", 21474836470);
		TEST_TEMPLATE("int min : %020x", -2147483647);
		//TEST_TEMPLATE("int min : %-0x", -2147483647);
		TEST_TEMPLATE("int min : %*x", 030, -2147483647);
		TEST_TEMPLATE("int min : %*x", -030, -2147483647);
		TEST_TEMPLATE("int min : %.20x", -2147483647);
		TEST_TEMPLATE("int min : %-.*x", 00, -2147483647);
		TEST_TEMPLATE("int min : %-.*x", 20, -2147483647);
		TEST_TEMPLATE("int min : %-.*x", -20, -2147483647);
		TEST_TEMPLATE("01.2: %01.*x", 2, 1);
		TEST_TEMPLATE("03.2 : %03.*x", 2, 1);
		TEST_TEMPLATE("-3.2 : %-3.*x", 2, 1);
		TEST_TEMPLATE("03.1 : %03.1x", -1);
		TEST_TEMPLATE("3 : %3x", 1);
		TEST_TEMPLATE("03.2 : %03.2x", 1);
		TEST_TEMPLATE("3.0 : %3.0x", 12);
		TEST_TEMPLATE("3.0 : %3.0x", 0);
		TEST_TEMPLATE(".0 : %.0x", 0);
		TEST_TEMPLATE(".1 : %.1x", 0);
		TEST_TEMPLATE(".3 : %.3x", 0);
		TEST_TEMPLATE(".0 : %.0x", -16);
		TEST_TEMPLATE(".0 : %.0x", 10);
		TEST_TEMPLATE(".1 : %.1x", 0);
		TEST_TEMPLATE(". : %.x", 0);
		TEST_TEMPLATE("62.1 : %.1x", 57);
		TEST_TEMPLATE("20.0 : %20.0x", 00);
		TEST_TEMPLATE("020.0 : %020.0x", 00);
		TEST_TEMPLATE(".1 : %.1x", -1);
		TEST_TEMPLATE(".2 : %.2x", -1);
		TEST_TEMPLATE(".3 : %.3x", -1);
		TEST_TEMPLATE("1 : %1x", -1);
		TEST_TEMPLATE("2 : %2x", -1);
		TEST_TEMPLATE("3 : %3x", -1);
		TEST_TEMPLATE("01 : %01x", -1);
		TEST_TEMPLATE("02 : %02x", -1);
		TEST_TEMPLATE("03 : %03x", -1);
		TEST_TEMPLATE("01.1 : %01.1x", -1);
		TEST_TEMPLATE("02.1 : %02.1x", -1);
		TEST_TEMPLATE("03.1 : %03.1x", -1);
		TEST_TEMPLATE("01.3 : %01.3x", -1);
		TEST_TEMPLATE("02.3 : %02.3x", -1);
		TEST_TEMPLATE("03.3 : %03.3x", -1);
		TEST_TEMPLATE("010.3 : %010.3x", -1);
		TEST_TEMPLATE("10.3 : %10.3x", -1);
		TEST_TEMPLATE("toto et %02x coco %-5x mimi", 19, (unsigned int)-20);
		printf("###############################################################################################\n\n"); fflush(NULL);
	}
		// -- with %% --
	if (atoi(av[1]) == 100 || atoi(av[1]) == 7 )
	{
		printf("\t\t\t--  1 : STRINGS WITH %% --\n\n"); fflush(NULL);
		TEST_TEMPLATE("rien : %%");
		TEST_TEMPLATE("0: %0%");
		TEST_TEMPLATE("01 :%01%");
		TEST_TEMPLATE("010 : %010%");
		TEST_TEMPLATE("0-1 : %0-1%");
		TEST_TEMPLATE("1 : %1%");
		TEST_TEMPLATE("2 : %2%");
		TEST_TEMPLATE("10 : %10%");
		TEST_TEMPLATE("-1 : %-1%");
		TEST_TEMPLATE("-2 : %-2%");
		TEST_TEMPLATE("-10 : %-10%");
		TEST_TEMPLATE("10.2 : %10.2%");
		TEST_TEMPLATE("010.2 : %010.2%");
		TEST_TEMPLATE("02.10 : %02.10%");
		TEST_TEMPLATE("2.10 : %2.10%");
		TEST_TEMPLATE("-2.10 : %-2.10%");
		TEST_TEMPLATE("-010 : %-010%");
		printf("###############################################################################################\n\n"); fflush(NULL);
	}
	return (0);
}