/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:15:39 by rde-jage          #+#    #+#             */
/*   Updated: 2017/06/21 17:46:23 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char *)(s1 - 1);
	ptr2 = (unsigned char *)(s2 - 1);
	while ((n > 0) && *(++ptr1) == *(++ptr2) && *ptr1 && *ptr2)
		n--;
	return (*ptr1 - *ptr2);
}
