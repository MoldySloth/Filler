/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:15:34 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/12 13:13:14 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_placement(t_play *a)
{
	ft_putnbr_fd(a->y_place, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(a->x_place, 1);
	ft_putchar_fd('\n', 1);
}

int		main(void)
{
	t_play		play;

	get_player_info(&play);
	while (1)
	{
		get_map_size(&play);
		get_map(&play);
		make_hmap(&play);
		init_hmap(&play);
		analyse_hmap(&play);
		get_piece_size(&play);
		get_piece(&play);
		place_init(&play);
		print_placement(&play);
		free_struct(&play);
		if (play.placed == false)
			break ;
	}
	return (0);
}
