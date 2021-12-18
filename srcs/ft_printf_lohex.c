/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lohex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:07:29 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/25 16:36:41 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_lohexcount(unsigned int x)
{
	int	size;

	size = 0;
	if (x == 0)
		return (1);
	while (x)
	{
		x = x / 16;
		size++;
	}
	return (size);
}

static char	*ft_itoa_lohex(unsigned int x)
{
	int		size;
	char	*rtn;
	char	*nbrs;

	nbrs = ft_printf_strdup("0123456789abcdef");
	size = ft_lohexcount(x);
	rtn = (char *)malloc(sizeof(char) * size + 1);
	if (!rtn)
		return (NULL);
	rtn[size] = '\0';
	while (--size >= 0)
	{
		rtn[size] = nbrs[x % 16];
		x = x / 16;
	}
	free((void *)nbrs);
	return (rtn);
}

int	ft_printf_lohex(unsigned int x)
{
	char	*str;
	int		rtn;

	rtn = 0;
	str = ft_itoa_lohex(x);
	rtn += ft_printf_str(str);
	return (rtn);
}
