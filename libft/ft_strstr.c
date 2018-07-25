/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:56:18 by rde-jage          #+#    #+#             */
/*   Updated: 2017/06/21 17:50:15 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	index;

	if (little[0] == '\0')
		return ((char *)big);
	while (*big)
	{
		index = 0;
		while (big[index] == little[index])
		{
			if (little[index + 1] == '\0')
				return ((char *)big);
			index++;
		}
		big++;
	}
	return (NULL);
}
