/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:56:05 by pmichale          #+#    #+#             */
/*   Updated: 2024/09/02 17:00:38 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Spaces are changed to S, change it back later..?
void	floodfill_s(char **map, int x, int y, int *error)
{
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
	{
		*error = 1;
		return ;
	}
	if (map[y][x] == ' ' || map[y][x] == '\t')
		map[y][x] = '1';
	if (y != 0 && map[y - 1][x] != '1'
		&& map[y - 1][x] != '\n' && map[y - 1][x])
		floodfill_s(map, x, y - 1, error);
	if (x != 0 && map[y][x - 1] != '1'
		&& map[y][x - 1] != '\n' && map[y][x - 1])
		floodfill_s(map, x - 1, y, error);
	if (map[y + 1][x] != '1' && map[y + 1][x] != '\n' && map[y + 1][x])
		floodfill_s(map, x, y + 1, error);
	if (map[y][x + 1] != '1' && map[y][x + 1] != '\n' && map[y][x + 1])
		floodfill_s(map, x + 1, y, error);
}

void	player_info(t_game *data, int x, int y)
{
	data->player.pos_x = x;
	data->player.pos_y = y;
	if (data->map[y][x] == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
	if (data->map[y][x] == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
	if (data->map[y][x] == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
	if (data->map[y][x] == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
	data->map[y][x] = '0';
}

void	tidy_up_map(t_game *data, char **map, int x, int y)
{
	if (map[y][x] == 0 && y < data->map_height
		&& x < data->map_widht + 1)
		map[y][x] = ' ';
	if (x == data->map_widht + 1)
		map[y][x] = 0;
}

void	vibe_check(char **map, int x, int y, int *error)
{
	if (map[y][x] != 0 && map[y][x] != '0' && map[y][x] != 'N'
			&& map[y][x] != 'S' && map[y][x] != 'E' && map[y][x] != 'W'
			&& map[y][x] != ' ' && map[y][x] != '\t' && map[y][x] != '\n'
			&& map[y][x] != '1')
		*error = 1;
	return ;
}

int	funfill(char **map, t_game *data, int x, int y)
{
	int	error;

	error = 0;
	while (map[y])
	{
		while (x - 2 != data->map_widht)
		{
			vibe_check(map, x, y, &error);
			tidy_up_map(data, map, x, y);
			if (error == 1)
				return (2);
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' ||
				map[y][x] == 'W')
				player_info(data, x, y);
			if (error == 1)
				return (9);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
