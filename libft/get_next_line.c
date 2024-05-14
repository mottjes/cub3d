/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:06:28 by mottjes           #+#    #+#             */
/*   Updated: 2024/01/30 12:13:47 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*delete_line_from_save(char *save)
{
	char	*new_save;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	i++;
	new_save = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!new_save)
	{
		free(save);
		return (NULL);
	}
	while (save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

char	*get_line_from_save(char *save)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = save[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*read_and_save(int fd, char *save)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(save), NULL);
	bytes_read = 1;
	while (!ft_strchr(save, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			free(save);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		save = append_buffer(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = get_line_from_save(save);
	if (!line)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = delete_line_from_save(save);
	return (line);
}
