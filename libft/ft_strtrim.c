/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:23:35 by rde-jage          #+#    #+#             */
/*   Updated: 2017/06/19 17:58:46 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*cpy;
	size_t	i;
	size_t	end;

	if (s == NULL)
		return (NULL);
	cpy = ft_strnew(ft_strlen(s));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	end = 0;
	if (ft_isspace(s[i]) ? 1 : 0)
		i++;
	while (i < (ft_strlen(s)))
	{
		if (!end && ft_isspace(s[i]))
			i++;
		else
			cpy[end++] = s[i++];
	}
	while (ft_isspace(cpy[--end]))
		cpy[end] = '\0';
	return (cpy);
}
