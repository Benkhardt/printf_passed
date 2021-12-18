/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:31:30 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/25 16:55:10 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lines(void *arg, const char format)
{
	int	rtn;

	rtn = 0;
	if (format == 'u')
		rtn += ft_printf_uint(*(unsigned int *)&arg);
	else if (format == 'x')
		rtn += ft_printf_lohex(*(unsigned int *)&arg);
	else if (format == 'X')
		rtn += ft_printf_uphex(*(unsigned int *)&arg);
	else if (format == 'c')
		rtn += ft_printf_char(*(char *)&arg);
	else if (format == '%')
		rtn += ft_printf_char('%');
	else if (format == 'd')
		rtn += ft_printf_int(*(int *)&arg);
	else if (format == 's')
		rtn += ft_printf_str((char *)arg);
	return (rtn);
}

int	ft_printf(const char *format, ...)
{
	t_mys	*z;

	z = (t_mys *)malloc(sizeof(t_mys));
	if (!z)
		return (0);
	z = ft_init(z);
	va_start(z->args, format);
	while (format[++z->i])
	{
		if (format[z->i] != '%')
			z->t_length += write(1, &format[z->i], 1);
		else
		{	
			if (format[++z->i] == 'p')
				z->t_length += ft_ptr((unsigned long)va_arg(z->args, void *));
			else if (format[z->i] == 'u' || format[z->i] == 'c'
				|| format[z->i] == 'x' || format[z->i] == 'X'
				|| format[z->i] == 'd' || format[z->i] == 's')
				z->t_length += ft_lines(va_arg(z->args, void *), format[z->i]);
			else if (format[z->i] == '%')
				z->t_length += write(1, "%", 1);
		}
	}
	va_end(z->args);
	return (z->t_length);
}
