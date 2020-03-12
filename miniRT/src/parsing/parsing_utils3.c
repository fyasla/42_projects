/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:09:18 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/12 16:22:34 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int	ft_atoi(char *str)
{
	int sg;
	int	res;

	sg = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sg = sg * (',' - *str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = 10 * res + (*str - '0');
		str++;
	}
	return (sg * res);
}

void	parsing_error(int ret, char *line, int l)
{
	free(line);
	if (ret == 1)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("Resolution (R) should specify 2 integers (>0) arguments : x_size and y_size\n");
	}
	else if (ret == -1)
	{		ft_printf("ERROR\nParsing error line %d\n", l);
			ft_printf(".rt files should have only one R specifier\n");
	}
	else if (ret == -2)
	{
		ft_printf("ERROR\nParsing error line %d\n, l");
		ft_printf(".rt files should have only one A specifier\n");
	}
	else if (ret == 2)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("Ambiant light (A) should specify 2 arguments : a RGB color and a light ratio\n");
	}
	else
		parsing_error2(ret, l);
	exit(EXIT_SUCCESS);
}

void	parsing_error2(int ret, int l)
{
	if (ret == 3)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("Cameras (c) should specify 3 arguments : coordinates, orientation and FOV\n");
	}
	else if (ret == -3)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("A lum ratio should be between 0 and 1\n");
	}
	else if (ret == -4)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("Maximum cameras number is %d\n", MAX_CAMS);
	}
	else if (ret == -5)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("Maximum lights number is %d\n", MAX_LIGHTS);
	}
	else
	parsing_error3(ret, l);
}

void	parsing_error3(int ret, int l)
{
	if (ret == 4)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("ligthts (l) should specify 3 arguments : coordinates, lum ratio and RGB color\n");
	}
	else if (ret == -6)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("Maximum objects number is %d\n", MAX_OBJS);
	}
	else if (ret == 5)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("spheres (sp) should specify 3 arguments : coordinates, diameter and RGB color\n");
	}
		else if (ret == -10)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("line should start with one of these specifiers : R,A,c,l,sp,pl,sq,cy,tr\n");
	}
	else
		parsing_error4(ret, l);
}

void	parsing_error4(int ret, int l)
{
	if (ret == 6)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("planes (pl) should specify 3 arguments : coordinates, orientation and RGB color\n");
	}
	else if (ret == 7)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("squarers (sq) should specify 4 arguments : coordinates, orientation, height and RGB color\n");
	}
	else if (ret == 8)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("cylinder (cy) should specify 5 arguments : coordinates, orientation, diameter, height and RGB color\n");
	}
	else if (ret == 9)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("triangles (tr) should specify 4 arguments : 3 points and RGB color\n");
	}
}