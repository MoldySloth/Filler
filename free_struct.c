/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:41:35 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/12 14:41:38 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	free_map(t_play *a)
{
	int		x;

	x = 0;
	while (x < a->m_rows)
	{
		free(a->m_data[x]);
		x++;
	}
	free(a->m_data);
}

static void	free_piece(t_play *a)
{
	int		x;

	x = 0;
	while (x < a->p_rows)
	{
		free(a->p_data[x]);
		x++;
	}
	free(a->p_data);
}

static void	free_hmap(t_play *a)
{
	int		x;

	x = 0;
	while (x < a->m_rows)
	{
		free(a->h_data[x]);
		x++;
	}
	free(a->h_data);
}

void		free_struct(t_play *a)
{
	free_map(a);
	free_piece(a);
	free_hmap(a);
}
