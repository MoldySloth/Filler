/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:02:19 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/12 13:14:05 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	make_map(t_play **a)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(((*a)->m_rows + 1) * sizeof(char *));
	i = 0;
	while (i < (*a)->m_rows)
	{
		arr[i] = (char *)malloc(((*a)->m_cols + 1) * sizeof(char));
		i++;
	}
	arr[i] = NULL;
	(*a)->m_data = arr;
}

void	get_map_size(t_play *a)
{
	char	**split_line;
	char	*line;

	get_next_line(0, &line);
	split_line = ft_strsplit(line, ' ');
	a->m_rows = ft_atoi(split_line[1]);
	a->m_cols = ft_atoi(split_line[2]);
	make_map(&a);
}

void	get_map(t_play *a)
{
	char	*line;
	int		y;
	int		x;

	y = 0;
	get_next_line(0, &line);
	while (y < a->m_rows)
	{
		get_next_line(0, &line);
		x = 0;
		while (x < a->m_cols && line[x])
		{
			a->m_data[y][x] = line[x + 4];
			x++;
		}
		a->m_data[y][x] = '\0';
		y++;
	}
}
