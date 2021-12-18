/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:07:48 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/25 16:37:03 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_itoa_hexcount(unsigned long p)
{
	int	size;

	size = 0;
	if (p == 0)
		return (1);
	while (p)
	{
		p = p / 16;
		size++;
	}
	return (size);
}

static char	*ft_itoa_hex(unsigned long p)
{
	int				size;
	char			*rtn;
	const char		*nbrs;

	nbrs = ft_printf_strdup("0123456789abcdef");
	size = ft_itoa_hexcount(p);
	rtn = (char *)malloc(sizeof(char) * size + 1);
	if (!rtn)
		return (0);
	rtn[++size] = '\0';
	while (--size >= 0)
	{
		rtn[size - 1] = nbrs[p % 16];
		p = p / 16;
	}
	free((void *)nbrs);
	return (rtn);
}

int	ft_ptr(unsigned long ptr)
{
	char	*p;
	int		rtn;

	p = ft_itoa_hex(ptr);
	rtn = 0;
	rtn += ft_printf_str("0x");
	rtn += ft_printf_str(p);
	return (rtn);
}
