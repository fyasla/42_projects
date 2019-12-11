/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:15:27 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/11 19:29:37 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

#define TEST_TEMPLATE(...) 	printf("ft_printf ||"); fflush(NULL);\
							ret = ft_printf(__VA_ARGS__);\
							printf("|| Retour : %d\n", ret); fflush(NULL);\
							printf("PRINTF    ||");\
							ret = printf(__VA_ARGS__);\
							printf("|| Retour : %d\n\n", ret);

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int ret;

	// -- without % --
	TEST_TEMPLATE("test");
	TEST_TEMPLATE("TEST");
	return (0);
}