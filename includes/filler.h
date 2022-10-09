/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:15:43 by egaliber          #+#    #+#             */
/*   Updated: 2022/10/09 12:00:01 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_filler
{
	int			player_num;
	char		me;
	char		enemy;
	int			map_hei;
	int			map_wid;
	int			piece_wid;
	int			piece_hei;
	int			**map;
	int			**piece;
	int			map_score;
	int			overlap;
	int			not_valid;
	int			best_score;
	int			best_y;
	int			best_x;
	int			border_y;
	int			border_x;
}				t_filler;

void	get_map_details(t_filler *filler, char *line);
void	init_filler(t_filler *filler);
void	get_players(t_filler *filler, char *line);
void	get_border_limit(t_filler *filler);
void	reset_filler(t_filler *filler);
void	free_board(t_filler *filler);
void	make_heatmap(t_filler *filler);

int		main(void);
int		get_information(t_filler *filler, char *line);
int		make_game(t_filler *filler, char *line);
int		get_map_values(t_filler *filler, char *line);
int		**make_map(int map_height, int map_width);
int		get_piece(t_filler *filler, char *line);
int		solver(t_filler *filler);
int		cleaner(t_filler *filler, char *line);
void	free_piece(t_filler *filler);

#endif