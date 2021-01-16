/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faysal <faysal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:21:50 by faysal            #+#    #+#             */
/*   Updated: 2021/01/16 03:42:14 by faysal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *s);
char	*strcpy(char *dest, const char *src);
int		strcmp(const char *s1, const char *s2);
size_t	write(int fd, const void *buf, size_t count);
size_t	read(int fd, void *buf, size_t count);
char	*strdup(const char *s);