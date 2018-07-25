/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 12:19:56 by rde-jage          #+#    #+#             */
/*   Updated: 2018/07/12 13:11:34 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_STRUCT_H
# define _FILLER_STRUCT_H

# include <unistd.h>
# include "./libft/libft.h"
# include <stdio.h>
# include <stdbool.h>

typedef struct		s_play
{
	int		m_cols;
	int		m_rows;
	char	**m_data;
	int		p_cols;
	int		p_rows;
	char	**p_data;
	int		**h_data;
	char	play_c;
	char	enemy;
	int		y_start;
	int		x_start;
	int		y;
	int		x;
	int		score;
	int		temp_score;
	int		y_temp;
	int		x_temp;
	int		y_place;
	int		x_place;
	bool	placed;
	int		overlap;
}					t_play;

#endif
