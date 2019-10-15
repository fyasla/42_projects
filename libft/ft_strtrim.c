/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:09:54 by fbougama          #+#    #+#             */
/*   Updated: 2019/10/15 13:46:05 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!(ptr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[start] && len-- > 0)
		ptr[i++] = s[start++];
	ptr[i++] = '\0';
	return (ptr);
}

int				ft_is_in(char c, char const *str)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;
	size_t			size;

	end = ft_strlen(s1) - 1;
	start = 0;
	while (ft_is_in(s1[start], set))
		start++;
	while (ft_is_in(s1[end], set))
		end--;
	size = end - start + 1;
	if (end < start)
		size = 0;
	return (ft_substr(s1, start, size));
}
