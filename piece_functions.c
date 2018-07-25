/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:24:36 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/12 13:25:24 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	make_piece(t_play **a)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(((*a)->p_rows + 1) * sizeof(char *));
	i = 0;
	while (i < (*a)->p_rows)
	{
		arr[i] = (char *)malloc(((*a)->p_cols + 1) * sizeof(char));
		i++;
	}
	arr[i] = NULL;
	(*a)->p_data = arr;
}

void	get_piece_size(t_play *a)
{
	char	**split_line;
	char	*line;

	get_next_line(0, &line);
	split_line = ft_strsplit(line, ' ');
	a->p_rows = ft_atoi(split_line[1]);
	a->p_cols = ft_atoi(split_line[2]);
	make_piece(&a);
}

void	get_piece(t_play *a)
{
	char	*line;
	int		y;
	int		x;

	y = 0;
	while (y < a->p_rows)
	{
		get_next_line(0, &line);
		x = 0;
		while (x < a->p_cols && line[x])
		{
			a->p_data[y][x] = line[x];
			x++;
		}
		a->p_data[y][x] = '\0';
		y++;
	}
}
