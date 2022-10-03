/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:29:33 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/03 21:22:25 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	best_result(t_filler *filler, int x, int y)
{
	if (filler->best_score == 0 || filler->map_score < filler->best_score)
	filler->best_score = filler->map_score;
	int y = filler->best_y;
	int x = filler->best_x;
}

int	placement(t_filler *filler, int x_total, int y_total)
{
	if (filler->board[y_total][x_total] == -2)
		return (0);
	if (filler->board[y_total][x_total] == -1)
	{
		filler->overlap++;
		if (filler->overlap > 1)
			return (0);
	}
	else
		filler->map_score += filler->board[y_total][x_total];
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
			if (filler->piece[y][x] == 1)
			{
				if (placement(filler, x + x_set, y + y_set) != 1)
					return (0);
			}
		}
	}

}


int	solver(t_filler *filler, int x, int y)
{
	int	valid;

	valid = 0;
	while (y <= filler->border_y)
	{
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
	{
		filler->not_valid = 1;
		ft_printf("0 0\n");
		return (0);
	}
	ft_printf("");
	return (0);
}