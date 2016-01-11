/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldubos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 07:44:34 by ldubos            #+#    #+#             */
/*   Updated: 2016/01/11 07:44:42 by ldubos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int			get_line(char **storage, char **line, int ret)
{
	char			*tmp;
	char			*off;

	tmp = *storage;
	off = ft_strchr(tmp, '\n');
	if (off)
	{
		*line = ft_strsub(tmp, 0, off - tmp);
		*storage = ft_strdup(off + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(tmp);
		free(*storage);
		*storage = NULL;
	}
	if ((!*line) || (off && !*storage))
		return (-1);
	if (!ret && *storage)
		return (1);
	return (ret);
}

static int			get_storage(int fd, char **storage)
{
	char			*buf;
	char			*tmp;
	int				ret;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	ret = 1;
	while ((ft_strchr(*storage, '\n') == NULL) && ret > 0)
	{
		tmp = *storage;
		ret = read(fd, buf, BUFF_SIZE);
		if (ret > 0)
		{
			buf[ret] = '\0';
			if (!(*storage = ft_strjoin(tmp, buf)))
			{
				*storage = ft_strcat(tmp, buf);
				free(buf);
				return (-1);
			}
			free(tmp);
		}
	}
	free(buf);
	return (ret);
}

int					get_next_line(int const fd, char **line)
{
	static char		*storage[512];
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	ret = 0;
	if (storage[fd] == NULL)
		if ((storage[fd] = ft_strnew(BUFF_SIZE * 2)) == NULL)
			return (-1);
	if (ft_strchr(storage[fd], '\n') == NULL)
		ret = get_storage(fd, &storage[fd]);
	if (ret > 1)
		ret = 1;
	if (ret == 0 && *storage[fd] == '\0')
	{
		*line = NULL;
		free(storage[fd]);
		storage[fd] = NULL;
	}
	else if (ret > 0 || *storage[fd] != '\0')
		ret = get_line(&storage[fd], line, ret);
	return (ret);
}

