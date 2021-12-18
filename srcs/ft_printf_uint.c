/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:41:51 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/25 16:36:49 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_uintcount(unsigned int u)
{
	int	size;

	size = 0;
	if (u == 0)
		return (1);
	while (u)
	{
		u = u / 10;
		size++;
	}
	return (size);
}

static char	*ft_itoa_uint(unsigned int u)
{
	int		size;
	char	*rtn;
	char	*nbrs;

	size = ft_uintcount(u);
	rtn = (char *)malloc(sizeof(char) * size + 1);
	if (!rtn)
		return (0);
	nbrs = ft_printf_strdup("0123456789");
	rtn[size] = '\0';
	while (size >= 0)
	{
		rtn[size - 1] = nbrs[u % 10];
		u = u / 10;
		size--;
	}
	free((void *)nbrs);
	return (rtn);
}

int	ft_printf_uint(unsigned int u)
{
	char	*str;
	int		rtn;

	rtn = 0;
	str = ft_itoa_uint(u);
	rtn += ft_printf_str(str);
	return (rtn);
}
