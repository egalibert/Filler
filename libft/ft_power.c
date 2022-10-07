/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 14:31:25 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/06 20:06:36 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_power(int power, long double base)
{
	int	i;
	int	number;

	number = 1.0;
	i = 0;
	while (i < power)
	{
		number *= base;
		i++;
	}
	return (number);
}
