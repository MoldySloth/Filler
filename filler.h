/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:19:56 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/12 13:10:59 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H

# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include "filler_struct.h"

void	print_placement(t_play *a);
void	print_map(char **arr);

void	get_player_info(t_play *a);
void	process_player(t_play *a, char *line);

void	get_map_size(t_play *a);
void	make_map(t_play **a);
void	get_map(t_play *a);

void	get_piece_size(t_play *a);
void	make_piece(t_play **a);
void	get_piece(t_play *a);

void	make_hmap(t_play *a);
void	fill_heat_map(t_play **a);
void	init_hmap(t_play *a);
void	analyse_hmap(t_play *a);

void	place_init(t_play *a);
void	place_piece(t_play *a);
int		is_valid(t_play *a);
int		check_chars(t_play *a, int y, int x);
void	check_next_star(t_play *a);
void	compare_score(t_play *a);
void	fill_map_fin(t_play *a);
void	free_struct(t_play *a);

#endif
