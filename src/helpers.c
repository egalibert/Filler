/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:17:37 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/05 00:38:41 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	reset_filler(t_filler *filler)
{

	filler->piece_wid = 0;
	filler->piece_hei = 0;
	filler->map_score = 0;
	filler->overlap = 0;
	filler->not_valid = 0;
	filler->best_score = 0;
	filler->best_x = 0;
	filler->best_y = 0;
}
