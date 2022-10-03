/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:18:09 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/03 21:41:31 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	make_game(t_filler *filler, char *line)
{
	if (ft_strstr(line, "   0"))
	{
		filler->board = make_board(filler->map_hei, filler->map_wid);
		get_map_details(filler, line);
	}
	return (0);
}

int	get_p_and_m(t_filler *filler, char *line)
{
	if (ft_strstr(line, "$$$ exec p"))
		get_players(filler, line);
	if (ft_strstr(line, "Plateau"))
		get_map_values(filler, line);
	return (0);
}

void init_filler(t_filler *filler)
{
	filler->player_num = 0;
	filler->map_hei = 0;
	filler->map_wid = 0;
	filler->board = 0;
	filler->piece_wid = 0;
	filler->piece_hei = 0;
	filler->map_score = 0;
	filler->overlap = 0;
	filler->not_valid = 0;
	filler->best_score = 0;
	filler->best_x = 0;
	filler->best_y = 0;

	// piece->piece_h = 0;
	// piece->piece_w = 0;
}

int main(int ac, char **av)
{
	char	*line;
	int		x;
	int		y;
	t_filler	*filler;

	x = 0;
	y = 0;
	init_filler(&filler);
	while (1)
	{
		if (get_next_line(0, &line) != 1)
			return (-1);
		if (get_p_and_m(&filler, line) != 0)
			return (-1);
		if (make_game(&filler, line) != 0)
			return (-1);
		make_heatmap(&filler);
		if (get_piece(&filler, line) != 0)
			return (-1);
		get_border_limit(&filler);
		if (solver(&filler, x, y) != 0)
			return (-1);
		
	}
	return (0);
}