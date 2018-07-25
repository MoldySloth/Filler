/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:41:11 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/13 11:41:36 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	process_player(t_play *a, char *line)
{
	char	**split_line;

	split_line = ft_strsplit(line, ' ');
	if (ft_memcmp(split_line[4], "[./filler]", 10) == 0)
	{
		if (ft_memcmp(split_line[2], "p1", 2) == 0)
		{
			a->play_c = 'O';
			a->enemy = 'X';
		}
		else if (ft_memcmp(split_line[2], "p2", 2) == 0)
		{
			a->play_c = 'X';
			a->enemy = 'O';
		}
	}
}

void	get_player_info(t_play *a)
{
	char	*line;

	get_next_line(0, &line);
	process_player(a, line);
}
