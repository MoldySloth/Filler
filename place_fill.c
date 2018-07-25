/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:37:53 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/13 10:37:58 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_chars(t_play *a, int y, int x)
{
	int		result;

	result = 2;
	if (a->p_data[y][x] == '*')
	{
		if ((a->y_start + y >= 0 && a->y_start + y < a->m_rows) &&
			(a->x_start + x >= 0 && a->x_start + x < a->m_cols))
		{
			if (a->h_data[a->y_start + y][a->x_start + x] == -1)
				result = 0;
			else if (a->h_data[a->y_start + y][a->x_start + x] == -2)
				result = 1;
		}
		else
			result = 0;
	}
	return (result);
}

int		is_valid(t_play *a)
{
	int		y;
	int		x;
	int		result;

	y = 0;
	a->overlap = 0;
	result = 0;
	while (y < a->p_rows)
	{
		x = 0;
		while (x < a->p_cols)
		{
			result = check_chars(a, y, x);
			if (result == 1)
				a->overlap++;
			else if (result == 0)
				return (0);
			x++;
		}
		y++;
	}
	if (a->overlap == 1)
		return (1);
	return (0);
}

void	place_piece_fin(t_play *a)
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
				a->y_place = a->y_start;
				a->x_place = a->x_start;
				a->placed = true;
			}
			x++;
		}
		y++;
	}
}

void	fill_map_fin(t_play *a)
{
	a->y_start = 0;
	a->x_start = 0;
	a->y = 0;
	a->placed = false;
	while (a->y < a->m_rows && a->placed == false)
	{
		a->x = 0;
		while (a->x < a->m_cols && a->placed == false)
		{
			if (a->h_data[a->y][a->x] == -2)
				place_piece_fin(a);
			a->x++;
		}
		a->y++;
	}
}
