/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:56:05 by pmichale          #+#    #+#             */
/*   Updated: 2024/09/02 18:00:50 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*pass_norminette(char *line, int fd_path, int *e)
{
	line = get_next_line(fd_path);
	if (line == NULL)
	{
		*e = 1;
		return (line);
	}
	while (line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd_path);
		if (line == NULL)
		{
			*e = 1;
			return (line);
		}
	}
	return (line);
}

char	*line2tex(char *line)
{
	char	*funny;
	int		lol;
	int		i;
	int		y;

	lol = 0;
	i = eat_w(line);
	y = eat_w(&line[i + 2]);
	funny = ft_strdup(&line[i + y + 2]);
	while (funny[lol])
	{
		if (funny[lol] == '\n')
			funny[lol] = 0;
		lol++;
	}
	return (funny);
}

int	parse_settings(int fd_path, t_game *data, char *line, int e)
{
	while (1)
	{
		free(line);
		line = pass_norminette(line, fd_path, &e);
		if (e == 1)
			return (1);
		if (line[eat_w(line)] == 'N' && line[eat_w(line) + 1] == 'O')
			data->texture_no.path = line2tex(line);
		else if (line[eat_w(line)] == 'S' && line[eat_w(line) + 1] == 'O')
			data->texture_so.path = line2tex(line);
		else if (line[eat_w(line)] == 'E' && line[eat_w(line) + 1] == 'A')
			data->texture_ea.path = line2tex(line);
		else if (line[eat_w(line)] == 'W' && line[eat_w(line) + 1] == 'E')
			data->texture_we.path = line2tex(line);
		else if (line[eat_w(line)] == 'F')
			e = parse_color(data, &line[eat_w(&line[eat_w(line) + 1])], 'F', 0);
		else if (line[eat_w(line)] == 'C')
			e = parse_color(data, &line[eat_w(&line[eat_w(line) + 1])], 'C', 0);
		else
			return (settings_set(fd_path, data, line));
		if (e == 1)
			return (7);
	}
	return (1);
}

int	parse_prep(int fd_path, t_game *data, char *path, int error)
{
	char	*line;

	if (check_path(path))
		return (1);
	line = malloc(1);
	data->color_ceiling = 0;
	data->color_floor = 0;
	data->texture_no.path = 0;
	data->texture_so.path = 0;
	data->texture_ea.path = 0;
	data->texture_we.path = 0;
	data->texture_no.img.img = 0;
	data->texture_so.img.img = 0;
	data->texture_we.img.img = 0;
	data->texture_ea.img.img = 0;
	data->map = 0;
	error = parse_settings(fd_path, data, line, 0);
	return (error);
}

int	cub_parser(char *path, t_game *data, int error)
{
	int	fd_path;

	fd_path = open(path, O_RDONLY);
	error = parse_prep(fd_path, data, path, 0);
	if (error > 0)
		write(2, "error\n", 6);
	if (error == 'N')
		write(2, "North Texture has not been set correctly.\n", 42);
	if (error == 'S')
		write(2, "South Texture has not been set correctly.\n", 42);
	if (error == 'E')
		write(2, "East Texture has not been set correctly.\n", 41);
	if (error == 'W')
		write(2, "West Texture has not been set correctly.\n", 41);
	if (error == 1)
		write(2, "Setting File incorrect\n", 23);
	if (error == 2)
		write(2, "Invalid Character in Map\n", 25);
	if (error == 7)
		write(2, "Color Invalid\n", 14);
	if (error == 8)
		write(2, "Multiple or no Player found.\n", 29);
	if (error == 9)
		write(2, "The Map is invalid.\n", 20);
	return (error);
}
