/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:24:21 by faysal            #+#    #+#             */
/*   Updated: 2020/06/25 16:34:23 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_scene	*parsing_error5(int ret, int l, t_scene *scene)
{
	if (ret == 10)
	{
		ft_printf("ERROR\nParsing error line %d\nFOV should ", l);
		ft_printf("be betweem 0 and 180\n");
	}
	return (scene);
}
