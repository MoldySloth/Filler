/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:48:25 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/12 14:48:28 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	do_stuff(t_play *a, int y, int x)
{
	if (a->temp_score == -2 && a->h_data[a->y_start + y][a->x_start + x] != 0)
		a->temp_score = a->h_data[a->y_start + y][a->x_start + x];
	else if (a->h_data[a->y_start + y][a->x_start + x] < a->temp_score &&
			a->h_data[a->y_start + y][a->x_start + x] > 0)
		a->temp_score = a->h_data[a->y_start + y][a->x_start + x];
}

void	check_next_star(t_play *a)
{
	int		y;
	int		x;

	y = 0;
	while (y < a->p_rows)
	{
		x = 0;
		while (x < a->p_cols)
		{
			if (a->p_data[y][x] == '*')
			{
				if (a->h_data[a->y_start + y][a->x_start + x] != -2)
					do_stuff(a, y, x);
			}
			x++;
		}
		y++;
	}
}

void	compare_score(t_play *a)
{
	if ((a->temp_score < a->score && a->temp_score != 0) || a->score == -2)
	{
		a->score = a->temp_score;
		a->y_place = a->y_start;
		a->x_place = a->x_start;
		a->placed = true;
	}
}

void	place_piece(t_play *a)
{
	int		y;
	int		x;

	y = 0;
	while (y < a->p_rows)
	{
		x = 0;
		while (x < a->p_cols)
		{
			a->y_start = (a->y - (a->p_rows - 1)) + y;
			a->x_start = (a->x - (a->p_cols - 1)) + x;
			if (is_valid(a))
			{
				check_next_star(a);
				compare_score(a);
			}
			x++;
		}
		y++;
	}
}

void	place_init(t_play *a)
{
	a->score = -2;
	a->temp_score = -2;
	a->y_start = 0;
	a->x_start = 0;
	a->y = 0;
	a->placed = false;
	while (a->y < a->m_rows)
	{
		a->x = 0;
		while (a->x < a->m_cols)
		{
			if (a->h_data[a->y][a->x] == -2)
				place_piece(a);
			a->x++;
		}
		a->y++;
	}
	if (a->temp_score == -2)
		fill_map_fin(a);
}
