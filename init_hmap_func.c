/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hmap_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:42:28 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/12 14:42:44 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	populate_hmap(t_play *a, int y, int x)
{
	if (x + 1 < a->m_cols && a->h_data[y][x + 1] == -1)
		a->h_data[y][x] = 1;
	else if (y + 1 < a->m_rows && a->h_data[y + 1][x] == -1)
		a->h_data[y][x] = 1;
	else if (x - 1 >= 0 && y + 1 < a->m_rows && a->h_data[y + 1][x - 1] == -1)
		a->h_data[y][x] = 1;
	else if (x - 1 >= 0 && a->h_data[y][x - 1] == -1)
		a->h_data[y][x] = 1;
	else if (x - 1 >= 0 && y - 1 >= 0 && a->h_data[y - 1][x - 1] == -1)
		a->h_data[y][x] = 1;
	else if (y - 1 >= 0 && a->h_data[y - 1][x] == -1)
		a->h_data[y][x] = 1;
	else if (x + 1 < a->m_cols && y - 1 >= 0 && a->h_data[y - 1][x + 1] == -1)
		a->h_data[y][x] = 1;
	else if (x + 1 < a->m_cols && y + 1 < a->m_rows &&
			a->h_data[y + 1][x + 1] == -1)
		a->h_data[y][x] = 1;
}

void		init_hmap(t_play *a)
{
	int		y;
	int		x;

	y = 0;
	while (y < a->m_rows)
	{
		x = 0;
		while (x < a->m_cols)
		{
			if (a->h_data[y][x] == 0)
				populate_hmap(a, y, x);
			x++;
		}
		y++;
	}
}

void		fill_heat_map(t_play **a)
{
	int		y;
	int		x;

	y = 0;
	while (y < (*a)->m_rows)
	{
		x = 0;
		while (x < (*a)->m_cols)
		{
			if ((*a)->m_data[y][x] == '.')
				(*a)->h_data[y][x] = 0;
			else if ((*a)->m_data[y][x] == (*a)->play_c ||
				(*a)->m_data[y][x] == ft_tolower((*a)->play_c))
			{
				(*a)->h_data[y][x] = (int)-2;
			}
			else if ((*a)->m_data[y][x] == (*a)->enemy ||
				(*a)->m_data[y][x] == ft_tolower((*a)->enemy))
			{
				(*a)->h_data[y][x] = (int)-1;
			}
			x++;
		}
		y++;
	}
}

void		make_hmap(t_play *a)
{
	int		i;

	a->h_data = (int **)malloc((a->m_rows) * sizeof(int *));
	i = 0;
	while (i < a->m_rows)
	{
		a->h_data[i] = (int *)malloc((a->m_cols) * sizeof(int));
		i++;
	}
	fill_heat_map(&a);
}
