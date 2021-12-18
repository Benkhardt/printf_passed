/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 08:14:02 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/25 16:36:23 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_intcount(long d)
{
	int	size;

	size = 0;
	if (d == 0)
		return (1);
	if (d < 0)
	{
		d = d * -1;
		size++;
	}
	while (d)
	{
		d = d / 10;
		size++;
	}
	return (size);
}

static char	*ft_itoa_int(long d)
{
	char	*rtn;
	char	*nbrs;
	int		size;

	size = ft_intcount(d);
	nbrs = ft_printf_strdup("0123456789");
	rtn = (char *)malloc(sizeof(char) * size + 1);
	if (!rtn)
		return (0);
	rtn[++size] = '\0';
	while (--size >= 0)
	{
		rtn[size - 1] = nbrs[d % 10];
		d = d / 10;
	}
	free((void *)nbrs);
	return (rtn);
}

int	ft_printf_int(int d)
{
	char	*str;
	int		rtn;
	long	c_d;

	rtn = 0;
	c_d = (long)d;
	if (c_d < 0)
	{
		rtn += ft_printf_char('-');
		c_d = c_d * -1;
	}
	str = ft_itoa_int(c_d);
	rtn += ft_printf_str(str);
	return (rtn);
}
