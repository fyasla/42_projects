/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:00:40 by fbougama          #+#    #+#             */
/*   Updated: 2019/12/19 13:16:04 by fbougama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

typedef struct	s_conv_spec
{
	char	flag;
	int		width;
	int		prec;
	char	type;
}				t_conv_spec;

int		ft_is_in(char c, char *str);
int		ft_fs_len(char *start);
int		ft_atoi(const char *str);
int		ft_nb_dec(int n);
char	*ft_itoa(int n);

void	manage_conv(const char *format, va_list ap, int *i, int *count);

int		is_in(char c, char *str);
int		cs_len(const char *format, char *conv_types);
char	*extract_cs(const char *format, int *i, char* conv_types);
int		star_prec_handler(t_conv_spec *cs, char *cs_str, int *i, va_list ap);
int		star_width_handler(t_conv_spec *cs, char *cs_str, int *i, va_list ap);

int		ft_isdigit(char c);
void	cs_flag(t_conv_spec *cs, char *cs_str, int *i);
void	cs_width(t_conv_spec *cs, char *cs_str, int *i);
void	cs_prec(t_conv_spec *cs, char *cs_str, int *i,va_list ap);
void	cs_parse(t_conv_spec *cs, char *cs_str, va_list ap);

int		conv_write(t_conv_spec *cs, va_list ap);

int		ft_dispatche(t_conv_spec *cs, va_list ap);

int		ft_write_c(t_conv_spec	*cs, va_list ap);
int		ft_write_s(t_conv_spec	*cs, va_list ap);
int		write_s_prec(t_conv_spec *cs, char *str);
int		write_s_width(t_conv_spec *cs, char *str);
int		ft_strlen(char *str);
// int		ft_write_p(t_conv_spec	*cs, va_list ap);
// int		ft_write_d(t_conv_spec	*cs, va_list ap);
// int		ft_write_i(t_conv_spec	*cs, va_list ap);
// int		ft_write_u(t_conv_spec	*cs, va_list ap);
// int		ft_write_x(t_conv_spec	*cs, va_list ap);
// int		ft_write_X(t_conv_spec	*cs, va_list ap);
// int		ft_write_pc(t_conv_spec	*cs, va_list ap);

int		ft_printf(const char *format, ...);

#endif
