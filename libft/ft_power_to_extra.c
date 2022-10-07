/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_to_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:57:54 by egaliber          #+#    #+#             */
/*   Updated: 2021/12/16 14:20:48 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power_to(int nb, int power)
{
	int		result;

	if (nb < 0)
		nb *= -1;
	if (power == 0)
		return (1);
	if ((power < 0) || (nb == 0))
		return (0);
	result = 1;
	while (power--)
		result *= nb;
	return (result);
}
