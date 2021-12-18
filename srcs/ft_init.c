/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:33:44 by dbenkhar          #+#    #+#             */
/*   Updated: 2021/10/25 16:55:29 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_mys	*ft_init(t_mys *zap)
{
	zap->t_length = 0;
	zap->i = -1;
	return (zap);
}