/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:24:14 by rde-jage          #+#    #+#             */
/*   Updated: 2017/06/19 17:53:33 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		i++;
	}
	if (str[0] != '\0')
		count++;
	return (count);
}

static char	*get_word(char const *str, char c, int *i)
{
	int		j;
	char	*s;

	j = 0;
	s = (char *)malloc(sizeof(s) * (ft_strlen((char*)str)));
	if (s == NULL)
		return (NULL);
	while (str[*i] && str[*i] != c)
	{
		s[j] = str[*i];
		j++;
		*i += 1;
	}
	s[j] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		word;
	char	**str;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	word = count_words(s, c);
	str = (char **)malloc(sizeof(str) * (word + 2));
	if (str == NULL)
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < word && s[i])
	{
		str[j] = get_word(s, c, &i);
		j++;
	}
	str[j] = NULL;
	return (str);
}
