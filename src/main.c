/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:18:09 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/09 13:05:31 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	get_map_info(t_filler *filler, char *line)
{
	if (get_map_values(filler, line) == -1)
		return (-1);
	if (filler->map == NULL)
		filler->map = make_map(filler->map_hei, filler->map_wid);
	if (filler->map == NULL)
		return (-1);
	get_map_details(filler, line);
	make_heatmap(filler);
	return (0);
}

int	get_information(t_filler *filler, char *line)
{
	if (ft_strstr(line, "$$$ exec p") && filler->player_num == 0)
	{
		get_players(filler, line);
		if (!filler->player_num)
			return (-1);
	}
	else if (ft_strstr(line, "Plateau"))
	{
		if (get_map_info(filler, line) == -1)
			return (-1);
	}
	else if (ft_strstr(line, "Piece"))
	{
		if (get_piece(filler, line) != 0)
			return (-1);
		if (solver(filler) != 0)
			return (-1);
	}
	ft_strdel(&line);
	return (0);
}

void	init_filler(t_filler *filler)
{
	filler->player_num = 0;
	filler->map_hei = 0;
	filler->map_wid = 0;
	filler->map = NULL;
	filler->piece_wid = 0;
	filler->piece_hei = 0;
	filler->map_score = 0;
	filler->overlap = 0;
	filler->not_valid = 0;
	filler->best_score = -1;
	filler->best_x = 0;
	filler->best_y = 0;
	filler->piece = NULL;
	filler->me = 0;
	filler->enemy = 0;
}

int	main(void)
{
	char		*line;
	t_filler	filler;

	init_filler(&filler);
	while (get_next_line(0, &line) > 0)
	{
		if (get_information(&filler, line) == -1)
			return (cleaner(&filler, line));
	}
	return (0);
}
