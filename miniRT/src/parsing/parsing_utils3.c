  /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:09:18 by fbougama          #+#    #+#             */
/*   Updated: 2020/03/12 17:00:46 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_atoi(char *str)
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

t_scene	*parsing_error(int ret, char *line, int l, t_scene *scene)
{
	free(line);
	if (ret == 1)
	{
		ft_printf("ERROR\nParsing error line %d\nResolution (R) should ", l);
		ft_printf("specify 2 integers (>0) arguments : x_size and y_size\n");
	}
	else if (ret == -1)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf(".rt files should have only one R specifier\n");
	}
	else if (ret == -2)
	{
		ft_printf("ERROR\nParsing error line %d\n, l");
		ft_printf(".rt files should have only one A specifier\n");
	}
	else if (ret == 2)
	{
		ft_printf("ERROR\nParsing error line %d\nAmbiant light (A) should ", l);
		ft_printf("specify 2 arguments : a RGB color and a light ratio\n");
	}
	else
		parsing_error2(ret, l, scene);
	exit(EXIT_SUCCESS);
}

t_scene	*parsing_error2(int ret, int l, t_scene *scene)
{
	if (ret == 3)
	{
		ft_printf("ERROR\nParsing error line %d\nCameras (c) should ", l);
		ft_printf("specify 3 arguments : coordinates, orientation and FOV\n");
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
		parsing_error3(ret, l, scene);
	return (scene);
}

t_scene	*parsing_error3(int ret, int l, t_scene *scene)
{
	if (ret == 4)
	{
		ft_printf("ERROR\nParsing error line %d\nligthts (l) should speci", l);
		ft_printf("fy 3 arguments : coordinates, lum ratio and RGB color\n");
	}
	else if (ret == -6)
	{
		ft_printf("ERROR\nParsing error line %d\n", l);
		ft_printf("Maximum objects number is %d\n", MAX_OBJS);
	}
	else if (ret == 5)
	{
		ft_printf("ERROR\nParsing error line %d\nspheres (sp) should spec", l);
		ft_printf("ify 3 arguments : coordinates, diameter and RGB color\n");
	}
	else if (ret == -10)
	{
		ft_printf("ERROR\nParsing error line %d\nline should start with ", l);
		ft_printf("one of these specifiers : R,A,c,l,sp,pl,sq,cy,tr\n");
	}
	else
		parsing_error4(ret, l, scene);
	return (scene);
}

t_scene	*parsing_error4(int ret, int l, t_scene *scene)
{
	if (ret == 6)
	{
		ft_printf("ERROR\nParsing error line %d\nplanes (pl) should speci", l);
		ft_printf("fy 3 arguments : coordinates, orientation and RGB color\n");
	}
	else if (ret == 7)
	{
		ft_printf("ERROR\nParsing error line %d\nsquarers (sq) should ", l);
		ft_printf("specify 4 arguments : coordinates");
		ft_printf(", orientation, height and RGB color\n");
	}
	else if (ret == 8)
	{
		ft_printf("ERROR\nParsing error line %d\ncylinder (cy) ", l);
		ft_printf("should specify 5 arguments : coordinates,");
		ft_printf(" orientation, diameter, height and RGB color\n");
	}
	else if (ret == 9)
	{
		ft_printf("ERROR\nParsing error line %d\ntriangles (tr) should ", l);
		ft_printf("specify 4 arguments : 3 points and RGB color\n");
	}
	else
		parsing_error5(ret, l, scene);
	return (scene);
}
