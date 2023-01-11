/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldgonza <aldgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:24:28 by aldgonza          #+#    #+#             */
/*   Updated: 2023/01/10 15:34:20 by aldgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

////////////////////////////////////////FREE
char	*ft_free_gnl(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin_gnl(buffer, buf);
	free(buffer);
	return (temp);
}

////////////////////////////////////////ADD_BUFF
char	*ft_add_buff(char *buffer, int fd)
{
	int		read_bytes;
	char	read_array[BUFFER_SIZE + 1];

	read_bytes = read(fd, read_array, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		read_array[read_bytes] = '\0';
		buffer = ft_free_gnl(buffer, read_array);
		if (ft_strchr_gnl(buffer, '\n') != -1)
			return (buffer);
		read_bytes = read(fd, read_array, BUFFER_SIZE);
	}
	if (read_bytes == 0 && !buffer)
		return (0);
	return (buffer);
}

////////////////////////////////////////ADD_LINE
char	*ft_add_line(char *buffer)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	len = ft_strchr_gnl(buffer, '\n');
	if (!buffer)
		return (0);
	if (len == -1)
		len = ft_strlen_gnl(buffer);
	ret = malloc((len + 2) * sizeof(char));
	if (!ret)
		return (0);
	ret[len + 1] = '\0';
	while (i < (len + 1))
	{
		ret[i] = buffer[i];
		i++;
	}
	return (ret);
}

////////////////////////////////////////CUT_BUFF
char	*ft_cut_buff(char *buffer)
{
	char	*temp;
	int		i;

	i = ft_strchr_gnl(buffer, '\n');
	if (i == ft_strlen_gnl(buffer) - 1)
	{
		free(buffer);
		return (0);
	}
	if (i == -1)
	{
		free(buffer);
		return (0);
	}
	temp = ft_substr_gnl(buffer, i + 1, ft_strlen_gnl(buffer));
	free(buffer);
	return (temp);
}

////////////////////////////////////////GNL :)
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) == -1))
		return (0);
	if (!buffer || (buffer && (ft_strchr_gnl(buffer, '\n') == -1)))
		buffer = ft_add_buff(buffer, fd);
	if (!buffer)
		return (0);
	line = ft_add_line(buffer);
	buffer = ft_cut_buff(buffer);
	return (line);
}
