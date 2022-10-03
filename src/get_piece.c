/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:44:23 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/03 17:18:15 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	give_value(t_filler *filler, char *line)
{
	int	y;
	int	x;

	y = 0;
	while(y < filler->piece_hei)
	{
		get_next_line(0, &line);
		line = ft_strchr(line, ' ') + 1;
		x = 0;
		while(x < filler->piece_wid)
		{
			if (line[x] == '*')
				filler->piece[y][x] = -1;
			if (line[x] == '.')
				filler->piece[y][x] = 0;
			x++;	
		}
		y++;
	}
}

int	get_piece_info(t_filler *filler, char *line)
{
	char	*row;
	char	*col;
	
	if (ft_strstr(line, "Piece"))
	{
	row = ft_strchr(line, ' ') + 1;
	col = ft_strchr(line, ' ') + 1;
	if (!row || !col)
		return (1);
	filler->piece_wid = ft_atoi(row);
	filler->piece_hei = ft_atoi(col);
	if (filler->piece_wid <= 0 || filler->piece_hei <= 0)
		return (1);
	}
	return (0);
}

int	get_piece(t_filler *filler, char *line)
{
	int i;

	i = 0;
	get_piece_info(filler, line);
	filler->piece = make_board(filler->piece_hei, filler->piece_wid);
	if (!filler->piece)
		return (NULL);
	give_value(filler, line);
	
	
	return (0);
}