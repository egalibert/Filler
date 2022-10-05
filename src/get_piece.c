/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:44:23 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/05 13:45:42 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	give_value(t_filler *filler, char *line)
{
	int	y;
	int	x;

	y = 0;
	while (y < filler->piece_hei)
	{
		get_next_line(0, &line);
		x = 0;
		while (x < filler->piece_wid)
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
	char	*width;
	char	*height;

	height = ft_strchr(line, ' ');
	width = ft_strrchr(line, ' ');
	if (!width || !height)
		return (0);
	filler->piece_wid = ft_atoi(width);
	filler->piece_hei = ft_atoi(height);
	if (filler->piece_wid <= 0 || filler->piece_hei <= 0)
		return (0);
	return (1);
}

int	get_piece(t_filler *filler, char *line)
{
	if (!get_piece_info(filler, line))
		return (-1);
	filler->piece = make_board(filler->piece_hei, filler->piece_wid);
	if (!filler->piece)
		return (-1);
	give_value(filler, line);
	filler->border_y = filler->map_hei - filler->piece_hei;
	filler->border_x = filler->map_wid - filler->piece_wid;
	return (0);
}
