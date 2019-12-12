/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:00:40 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/12 19:22:41 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct	s_form_spec
{
	char	flag;
	int		width;
	int		prec;
	int		size;
	char	type;
}				t_form_spec;

int		ft_is_in(char c, char *str);
int		ft_fs_len(char *start);
int		ft_atoi(const char *str);
int		ft_nb_dec(int n)
char	*ft_itoa(int n)
int		ft_printf(const char *format, ...);

#endif
