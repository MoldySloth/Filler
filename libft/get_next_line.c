/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:05:03 by rde-jage          #+#    #+#             */
/*   Updated: 2018/06/22 13:55:18 by rde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read_buffer(int const fd, char **line)
{
	char	*buff;
	int		counter;
	char	*temp;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	counter = read(fd, buff, BUFF_SIZE);
	if (counter > 0)
	{
		buff[counter] = '\0';
		temp = ft_strjoin(*line, buff);
		*line = temp;
	}
	return (counter);
}

int			get_next_line(int const fd, char **line)
{
	static char	*str;
	char		*find_line;
	int			result;

	if ((!str && (str = (char *)malloc(sizeof(*str))) == NULL) || !line ||
			fd < 0 || BUFF_SIZE < 0)
		return (-1);
	find_line = ft_strchr(str, '\n');
	while (find_line == NULL)
	{
		result = ft_read_buffer(fd, &str);
		if (result == 0)
		{
			if (ft_strlen(str) == 0)
				return (0);
			str = ft_strjoin(str, "\n");
		}
		if (result < 0)
			return (-1);
		else
			find_line = ft_strchr(str, '\n');
	}
	*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(find_line));
	str = ft_strdup(find_line + 1);
	return (1);
}
