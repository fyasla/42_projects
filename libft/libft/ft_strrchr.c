/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:46:04 by fbougama          #+#    #+#             */
/*   Updated: 2021/09/02 17:33:43 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = 0;
	while (len >= 0 && *(s + len) != c)
		len--;
	if (len >= 0)
		return ((char *)s + len);
	else
		return (NULL);
}
