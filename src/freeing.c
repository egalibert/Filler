/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:26:33 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/06 03:37:42 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_board(t_filler *filler)
{
	int	i;

	i = 0;
	if (filler->map)
	{
		while (i < filler->map_hei)
		{
			free(filler->map[i]);
			i++;
		}
		free(filler->map);
	}
	filler->map = NULL;
}

void	free_piece(t_filler *filler)
{
	int	j;

	j = 0;
	if (filler->piece)
	{
		while (j < filler->piece_hei)
		{
			free(filler->piece[j]);
			j++;
		}
		free(filler->piece);
	}
	filler->piece = NULL;
}

int	cleaner(t_filler *filler, char *line)
{
	free_board(filler);
	free_piece(filler);
	ft_strdel(&line);
	ft_putnbr(0);
	ft_putchar(' ');
	ft_putnbr(0);
	ft_putchar('\n');
	return (0);
}
