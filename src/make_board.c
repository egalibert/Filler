/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:26:58 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/03 21:00:41 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_map_details(t_filler *filler, char *line)
{
	int y_cord;
	int x_cord;
	
	y_cord = 0;
	while (y_cord < filler->map_hei)
	{
		get_next_line(0, &line);
		line = ft_strchr(line, ' ') + 1;
		x_cord = 0;
		while(x_cord < filler->map_wid)
		{
			if (line[x_cord] == filler->enemy || filler->enemy + 32)
				filler->board[y_cord][x_cord] = -2;
			if (line[x_cord] == filler->me || filler->me + 32)
				filler->board[y_cord][x_cord] = -1;
			if (line[x_cord] == '.')
				filler->board[y_cord][x_cord] = 0;
			x_cord++;
		}
		y_cord++;
	}
	return (0);
}

int	**make_board(int map_height, int map_width)
{
	int	a;
	int	b;
	int **board;

	board = (int **)malloc(sizeof(int *) * map_width);
	a = 0;
	while (a < map_width)
	{
		board[a] = (int *)malloc(sizeof(int)* map_height);
	}
	b = 0;
	while (b < map_height)
	{
		board[a][b] = 0;
		b++;
	}
	a++;
	return(board);
}