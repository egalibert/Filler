/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:26:33 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/04 00:16:47 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_board(t_filler *filler)
{
	int	i;

	i = 0;
	while (filler->board[i])
		if (filler->board[i])
			free(filler->board[i++]);
	if (filler->board)
		free(filler->board);
	filler->board = NULL;
}

void	free_piece(t_filler *filler)
{
	int j;

	j = -1;
	while (filler->piece[++j])
		if (filler->piece[j])
			free(filler->piece[j]);
	if (filler->piece)
		free(filler->piece);
	filler->piece = NULL;
}

int	cleaner(t_filler *filler, char *line)
{
	free_board(filler);
	free_piece(filler);
	ft_strdel(&line);
	return (0);
}