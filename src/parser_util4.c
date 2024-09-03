/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:38:37 by pmichale          #+#    #+#             */
/*   Updated: 2024/09/03 15:06:26 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_path(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (path[i - 1] == 'b' && path[i - 2] == 'u'
		&& path[i - 3] == 'c' && path[i - 4] == '.')
		return (0);
	return (1);
}

int	parse_more(char *line, t_game *data, int *error)
{
	if (line[eat_w(line)] == 'N' && line[eat_w(line) + 1] == 'O')
		data->texture_no.path = line2tex(line, data->texture_no, error);
	else if (line[eat_w(line)] == 'S' && line[eat_w(line) + 1] == 'O')
		data->texture_so.path = line2tex(line, data->texture_so, error);
	else if (line[eat_w(line)] == 'E' && line[eat_w(line) + 1] == 'A')
		data->texture_ea.path = line2tex(line, data->texture_ea, error);
	else if (line[eat_w(line)] == 'W' && line[eat_w(line) + 1] == 'E')
		data->texture_we.path = line2tex(line, data->texture_we, error);
	else
		return (0);
	if (*error == 2)
		free(line);
	return (1);
}
