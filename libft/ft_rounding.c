/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:33:15 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/07 12:45:59 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_rounding(int i, long double num)
{
	long double	round;
	long double	r;

	r = 0.5;
	while (i > 0)
	{
		r = r / 10.0;
		i--;
	}
	round = num + r;
	return (round);
}
