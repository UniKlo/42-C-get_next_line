/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 12:53:01 by khou              #+#    #+#             */
/*   Updated: 2018/08/03 14:35:57 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_begin(char **str, char **line)
{
	char	*beg;

	if ((*str)[0] == '\0')//nothing in file
		return (0);
	if (ft_strchr(*str, '\n') && !(*(ft_strchr(*str, '\n')) = '\0'))
	{
		*line = ft_strdup(*str);
		beg = ft_strdup(ft_strchr(*str, '\0') + 1);
		free(*str);
		*str = beg;
	}
	else
	{
		*line = ft_strdup(*str);
		ft_memdel((void **)str);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	int			ret;
	static char	*str[4865];
	char		*holder;

	if (fd < 0 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	(!str[fd]) && (str[fd] = ft_strnew(0));
	while (!ft_strchr(str[fd], '\n') && (ret = read(fd, buffer, BUFF_SIZE)))//if read once does not find '/n'
	{
		buffer[ret] = '\0';
		holder = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = ft_strdup(holder);
		free(holder);
	}
/*	if (!ft_strlen(holder))//if read does not 
		return (0);
*/
	return (get_begin(&str[fd], line));//if read line is shorter than BUFF_SIZE or found '/n'
}
