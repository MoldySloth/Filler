/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:52:16 by rde-jage          #+#    #+#             */
/*   Updated: 2017/07/11 14:39:47 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numbers_part(const char *str, long long num, int neg)
{
	while (*str <= '9' && *str >= '0')
	{
		num = num * 10 + *str - '0';
		str++;
		if (num < 0)
		{
			if (neg == 1)
				return (0);
			return (-1);
		}
	}
	if (neg)
		num = -num;
	return (num);
}

int			ft_atoi(const char *str)
{
	long long	num;
	int			neg;

	neg = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' && str++)
		neg = 1;
	else if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	num = 0;
	return (numbers_part(str, num, neg));
}
