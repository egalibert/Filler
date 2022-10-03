/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:15:56 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/03 21:40:01 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	all_range(t_filler *filler, int x, int y, int i)
{
	if (x + 1 < filler->map_wid && filler->board[y][x + 1] == i)
		filler->board[y][x] = i + 1;
	if (x + 1 < filler->map_wid && y - 1 >= 0 && filler->board[y - 1][x + 1] == i)
		filler->board[y][x] = i + 1;
	if (y - 1 >= 0 && filler->board[y - 1][x] == i)
		filler->board[y][x] = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && filler->board[y - 1][x - 1] == i)
		filler->board[y][x] = i + 1;
	if (x - 1 >= 0 && filler->board[y][x - 1] == i)
		filler->board[y][x] = i + 1;
	if (x - 1 >= 0 && y + 1 < filler->map_hei && filler->board[y + 1][x - 1] == i)
		filler->board[y][x] = i + 1;
	if (y + 1 < filler->map_hei && filler->board[y + 1][x] == i)
		filler->board[y][x] = i + 1;
	if (y + 1 < filler->map_hei && x + 1 < filler->map_wid && \
		filler->board[y + 1][x + 1]== i)
		filler->board[y][x] = i + 1;
}

static void	fill_rest(t_filler *filler)
{
	int	i;
	int	x;
	int	y;
	int	max;

	if (filler->map_wid > filler->map_hei)
		max = filler->map_wid;
	else
		max = filler->map_hei;
	i = 0;
	while (++i < max)
	{
		y = 0;
		while (y++ < filler->map_hei)
		{
			x = 0;
			while (x++ < filler->map_wid)
				if (filler->board[y][x] == 0)
					range_all(filler, x, y, i);
		}
	}
}

void	range_one(t_filler *filler, int x, int y)
{
	if (x + 1 < filler->map_wid && filler->board[y][x + 1] == -2)
		filler->board[y][x] = 1;
	if (y + 1 < filler->map_hei && filler->board[y + 1][x] == -2)
		filler->board[y][x] = 1;
	if (x - 1 >= 0 && filler->board[x - 1][y] == -2)
		filler->board[x][y] = 1;
	if (y - 1 >= 0 && filler->board[x][y - 1] == -2)
		filler->board[x][y] = 1;
	if (x + 1 < filler->map_wid && y + 1 < filler->map_hei && \
		filler->board[y + 1][x + 1] == -2);
		filler->board[y][x] = 1;
	if (x - 1 >= 0 && y - 1 >= 0 && filler->board[y - 1][x - 1] == -2)
		filler->board[y][x] = 1;
	if (x - 1 >= 0 && y + 1 < filler->map_hei && filler->board[y + 1][x - 1] == -2)
		filler->board[y][x] = 1;
	if (x + 1 < filler->map_wid && y - 1 >= 0 && filler->board[y - 1][x + 1] == -2)
		filler->board[y][x] = 1;
}

void	fill_heatmap(t_filler *filler)
{
	int y;
	int x;

	y = -1;
	while (y++ < filler->map_hei)
	{
		x = -1;
		while (x++ < filler->map_wid)
		{
			if (filler->board[y][x] == 0)
				range_one(filler, x, y);
		}
	}
}

void	make_heatmap(t_filler *filler)
{
	fill_heatmap(filler);
	fill_rest(filler);
}