/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:32:13 by rde-jage          #+#    #+#             */
/*   Updated: 2017/06/11 14:37:40 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*csrc;
	unsigned char	*cdst;

	i = 0;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	while (n > i)
	{
		cdst[i] = csrc[i];
		if (csrc[i] == (unsigned char)c)
			return (void *)&(cdst[i + 1]);
		i++;
	}
	return (NULL);
}
