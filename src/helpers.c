/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:17:37 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/03 22:30:07 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_border_limit(t_filler *filler)
{
	filler->border_y = filler->map_hei - filler->piece_hei;
	filler->border_x = filler->map_wid - filler->piece_wid;
}

void	reset_filler(t_filler *filler)
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
}
