/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:59:19 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/25 17:01:11 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct m_s
{
	va_list	args;
	int		i;
	int		t_length;
}	t_mys;

t_mys	*ft_init(t_mys *zap);
int		ft_printf(const char *format, ...);
int		ft_printf_char(char c);
int		ft_printf_str(char *s);
int		ft_ptr(unsigned long ptr);
int		ft_printf_int(int d);
int		ft_printf_uint(unsigned int u);
int		ft_printf_lohex(unsigned int x);
int		ft_printf_uphex(unsigned int x);
char	*ft_printf_strdup(const char *s1);

#endif
