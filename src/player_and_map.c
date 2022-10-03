/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_and_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:39:45 by egaliber          #+#    #+#             */
/*   Updated: 2022/09/29 22:12:23 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get_map_values(t_filler *filler, char* line)
{
	char *y;
	char *x;
	
	x = ft_strchr(line, ' ');
	y = ft_strchr(line, ' ');
	if (x == 0 || y == 0)
		return (1);
	filler->map_hei = ft_atoi(x);
	filler->map_wid = ft_atoi(y);
	return (0);
}

void	get_players(t_filler *filler, char *line)
{
	char	*p_nbr;
	
	p_nbr = ft_strchr(line, 'p');
	filler->player_num = ft_atoi(p_nbr + 1);
	if (filler->player_num == 1)
	{
		filler->me = 'O';
		filler->enemy = 'X';
	}
	else if (filler->player_num == 2)
	{
		filler->me = 'X';
		filler->enemy = 'O';
	}
}
