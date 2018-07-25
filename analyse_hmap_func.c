/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_hmap_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:36:57 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/12 14:37:02 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	do_hmap(t_play *a, int i, int y, int x)
{
	if (x + 1 < a->m_cols && a->h_data[y][x + 1] == i)
		a->h_data[y][x] = i + 1;
	else if (y + 1 < a->m_rows && a->h_data[y + 1][x] == i)
		a->h_data[y][x] = i + 1;
	else if (x - 1 >= 0 && y + 1 < a->m_rows && a->h_data[y + 1][x - 1] == i)
		a->h_data[y][x] = i + 1;
	else if (x - 1 >= 0 && a->h_data[y][x - 1] == i)
		a->h_data[y][x] = i + 1;
	else if (x - 1 >= 0 && y - 1 >= 0 && a->h_data[y - 1][x - 1] == i)
		a->h_data[y][x] = i + 1;
	else if (y - 1 >= 0 && a->h_data[y - 1][x] == i)
		a->h_data[y][x] = i + 1;
	else if (x + 1 < a->m_cols && y - 1 >= 0 && a->h_data[y - 1][x + 1] == i)
		a->h_data[y][x] = i + 1;
	else if (x + 1 < a->m_cols && y + 1 < a->m_rows &&
			a->h_data[y + 1][x + 1] == i)
		a->h_data[y][x] = i + 1;
}

void		analyse_hmap(t_play *a)
{
	int		y;
	int		x;
	int		i;

	i = 1;
	while (i < a->m_cols)
	{
		y = 0;
		while (y < a->m_rows)
		{
			x = 0;
			while (x < a->m_cols)
			{
				if (a->h_data[y][x] == 0)
					do_hmap(a, i, y, x);
				x++;
			}
			y++;
		}
		i++;
	}
}
