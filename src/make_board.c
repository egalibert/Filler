/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:26:58 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/05 13:48:56 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_map_details(t_filler *filler, char *line)
{
	int	y_cord;
	int	x_cord;

	y_cord = 0;
	while (y_cord < filler->map_hei)
	{
		get_next_line(0, &line);
		line = ft_strchr(line, ' ') + 1;
		x_cord = 0;
		while (x_cord < filler->map_wid)
		{
			if (line[x_cord] == filler->enemy || line[x_cord] == filler->enemy + 32)
				filler->board[y_cord][x_cord] = -2;
			else if (line[x_cord] == filler->me || line[x_cord] == filler->me + 32)
				filler->board[y_cord][x_cord] = -1;
			else
				filler->board[y_cord][x_cord] = 0;
			x_cord++;
		}
		y_cord++;
	}
}

int	**make_board(int map_height, int map_width)
{
	int	y;
	int	x;
	int	**board;

	board = (int **)malloc(sizeof(int *) * map_height);
	y = 0;
	while (y < map_height)
	{
		board[y] = (int *)malloc(sizeof(int) * map_width);
		x = 0;
		while (x < map_width)
		{
			board[y][x] = 0;
			x++;
		}
		y++;
	}
	return (board);
}
