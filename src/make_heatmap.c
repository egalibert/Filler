/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:15:56 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/06 03:36:20 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	range_all(t_filler *filler, int x, int y, int i)
{
	if (x + 1 < filler->map_wid && filler->map[y][x + 1] == i)
		filler->map[y][x] = i + 1;
	if (x + 1 < filler->map_wid && y - 1 >= 0 && filler->map[y - 1][x + 1] == i)
		filler->map[y][x] = i + 1;
	if (y - 1 >= 0 && filler->map[y - 1][x] == i)
		filler->map[y][x] = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && filler->map[y - 1][x - 1] == i)
		filler->map[y][x] = i + 1;
	if (x - 1 >= 0 && filler->map[y][x - 1] == i)
		filler->map[y][x] = i + 1;
	if (x - 1 >= 0 && y + 1 < filler->map_hei && filler->map[y + 1][x - 1] == i)
		filler->map[y][x] = i + 1;
	if (y + 1 < filler->map_hei && filler->map[y + 1][x] == i)
		filler->map[y][x] = i + 1;
	if (y + 1 < filler->map_hei && x + 1 < filler->map_wid && \
		filler->map[y + 1][x + 1] == i)
		filler->map[y][x] = i + 1;
}

void	fill_rest(t_filler *filler)
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
		y = -1;
		while (++y < filler->map_hei)
		{
			x = -1;
			while (++x < filler->map_wid)
				if (filler->map[y][x] == 0)
					range_all(filler, x, y, i);
		}
	}
}

void	range_one(t_filler *filler, int x, int y)
{
	if (x + 1 < filler->map_wid && filler->map[y][x + 1] == -2)
		filler->map[y][x] = 1;
	if (x + 1 < filler->map_wid && y - 1 >= 0 && \
		filler->map[y - 1][x + 1] == -2)
		filler->map[y][x] = 1;
	if (y - 1 >= 0 && filler->map[y - 1][x] == -2)
		filler->map[y][x] = 1;
	if (x - 1 >= 0 && y - 1 >= 0 && filler->map[y - 1][x - 1] == -2)
		filler->map[y][x] = 1;
	if (x - 1 >= 0 && filler->map[y][x - 1] == -2)
		filler->map[y][x] = 1;
	if (x - 1 >= 0 && y + 1 < filler->map_hei && \
		filler->map[y + 1][x - 1] == -2)
		filler->map[y][x] = 1;
	if (y + 1 < filler->map_hei && filler->map[y + 1][x] == -2)
		filler->map[y][x] = 1;
	if (y + 1 < filler->map_hei && x + 1 < filler->map_wid && \
		filler->map[y + 1][x + 1] == -2)
		filler->map[y][x] = 1;
}

void	fill_heatmap(t_filler *filler)
{
	int	y;
	int	x;

	y = -1;
	while (++y < filler->map_hei)
	{
		x = -1;
		while (++x < filler->map_wid)
		{
			if (filler->map[y][x] == 0)
				range_one(filler, x, y);
		}
	}
}

void	make_heatmap(t_filler *filler)
{
	fill_heatmap(filler);
	fill_rest(filler);
}
