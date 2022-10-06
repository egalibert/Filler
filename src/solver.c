/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:29:33 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/06 03:33:55 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	best_result(t_filler *filler, int x, int y)
{
	if (filler->best_score == -1 || filler->map_score < filler->best_score)
	{
		filler->best_score = filler->map_score;
		filler->best_y = y;
		filler->best_x = x;
	}
}

int	placement(t_filler *filler, int x_total, int y_total)
{
	if (filler->map[y_total][x_total] == -2)
		return (0);
	else if (filler->map[y_total][x_total] == -1)
	{
		filler->overlap++;
		if (filler->overlap > 1)
			return (0);
	}
	else
		filler->map_score += filler->map[y_total][x_total];
	return (1);
}

int	get_valid(t_filler *filler, int x_set, int y_set)
{
	int	x;
	int	y;

	filler->overlap = 0;
	filler->map_score = 0;
	y = 0;
	while (y < filler->piece_hei)
	{
		x = 0;
		while (x < filler->piece_wid)
		{
			if (filler->piece[y][x] == -1)
			{
				if (placement(filler, x + x_set, y + y_set) != 1)
					return (0);
			}
			x++;
		}
		y++;
	}
	if (filler->overlap != 1)
		return (0);
	return (1);
}

int	solver(t_filler *filler)
{
	int	x;
	int	y;
	int	valid;

	valid = 0;
	y = 0;
	while (y <= filler->border_y)
	{
		x = 0;
		while (x <= filler->border_x)
		{
			if (get_valid(filler, x, y))
			{
				valid++;
				best_result(filler, x, y);
			}
			x++;
		}
		y++;
	}
	if (valid == 0)
		return (-1);
	ft_putnbr(filler->best_y);
	ft_putchar(' ');
	ft_putnbr(filler->best_x);
	ft_putchar('\n');
	reset_filler(filler);
	return (0);
}
