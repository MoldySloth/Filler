/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:18:17 by rde-jage          #+#    #+#             */
/*   Updated: 2017/06/11 12:29:34 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *string, size_t maxlen)
{
	const char *end;

	end = ft_memchr(string, '\0', maxlen);
	return (end ? (size_t)(end - string) : maxlen);
}
