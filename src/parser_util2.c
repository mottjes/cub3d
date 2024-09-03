/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmichale <pmichale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:56:05 by pmichale          #+#    #+#             */
/*   Updated: 2024/09/02 17:56:08 by pmichale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this code is responsible to find whitespaces and start
// floodfills on them, making sure they are surrounded by walls
int	outerfill(char **map, t_game *data, int x, int y)
{
	int	error;

	error = funfill(map, data, 0, 0);
	while (map[y])
	{
		while (x - 2 != data->map_widht)
		{
			if (error != 0)
				return (error);
			if (map[y][x] == '\t' || map[y][x] == ' ')
				floodfill_s(map, x, y, &error);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	map_sizes(char **map, t_game *data, int wi, int l)
{
	int	w;
	int	flag;

	flag = 0;
	w = 0;
	while (map[l + 2])
	{
		while (map[l][w])
		{
			if (map[l][w] == 'N' || map[l][w] == 'S' || map[l][w] == 'E'
				|| map[l][w] == 'W')
				flag++;
			w++;
		}
		if (w > wi)
			wi = w;
		w = 0;
		l++;
	}
	if (flag != 1)
		return (8);
	data->map_height = l + 1;
	data->map_widht = wi - 1;
	return (outerfill(map, data, 0, 0));
}

// fills a row with spaces, for the sake of floodfill
void	row_ws(char **map, int y)
{
	int	i;

	i = 0;
	map[y] = calloc(1024, sizeof(char));
	while (i != 1020)
	{
		map[y][i] = ' ';
		i++;
	}
}

char	**map_gen(char **map, t_game *data, char *line, int fd_path)
{
	char	*buffer;
	int		i;

	map = ft_calloc(1024, sizeof(char *));
	i = 0;
	row_ws(map, i);
	i++;
	while (line != NULL)
	{
		buffer = ft_calloc(1024, sizeof(char));
		buffer[0] = ' ';
		ft_strlcpy(&buffer[1], line, ft_strlen(line));
		buffer[ft_strlen(buffer)] = ' ';
		map[i] = buffer;
		free(line);
		i++;
		line = get_next_line(fd_path);
	}
	buffer[ft_strlen(buffer)] = ' ';
	row_ws(map, i);
	i++;
	map[i] = ft_calloc(1024, sizeof(char));
	data->map = map;
	return (map);
}

int	settings_set(int fd_path, t_game *data, char *line)
{
	char	**map;

	map = NULL;
	if (data->texture_no.path == 0)
	{
		free(line);
		return ('N');
	}
	if (data->texture_so.path == 0)
	{
		free(line);
		return ('S');
	}
	if (data->texture_ea.path == 0)
	{
		free(line);
		return ('E');
	}
	if (data->texture_we.path == 0)
	{
		free(line);
		return ('W');
	}
	map = map_gen(map, data, line, fd_path);
	return (map_sizes(map, data, 0, 1));
}
