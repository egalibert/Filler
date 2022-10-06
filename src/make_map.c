/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:26:58 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/06 03:32:04 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_map_details(t_filler *filler, char *line)
{
	int		y;
	int		x;
	char	*str;

	get_next_line(0, &line);
	ft_strdel(&line);
	y = 0;
	while (y < filler->map_hei && get_next_line(0, &line) > 0)
	{
		str = line;
		line = ft_strchr(line, ' ') + 1;
		x = 0;
		while (x < filler->map_wid)
		{
			if (line[x] == filler->enemy || line[x] == filler->enemy + 32)
				filler->map[y][x] = -2;
			else if (line[x] == filler->me || line[x] == filler->me + 32)
				filler->map[y][x] = -1;
			else
				filler->map[y][x] = 0;
			x++;
		}
		y++;
		ft_strdel(&str);
	}
}

int	**make_map(int map_height, int map_width)
{
	int	y;
	int	x;
	int	**map;

	map = (int **)malloc(sizeof(int *) * map_height);
	y = 0;
	while (y < map_height)
	{
		map[y] = (int *)malloc(sizeof(int) * map_width);
		x = 0;
		while (x < map_width)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (map);
}
