/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:41:33 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/22 03:23:51 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_str(char *s)
{
	int	rtn;
	int	index;

	rtn = 0;
	index = -1;
	while (s[++index])
		rtn += write(1, &s[index], 1);
	return (rtn);
}
