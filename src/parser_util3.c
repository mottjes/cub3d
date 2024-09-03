/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:56:05 by pmichale          #+#    #+#             */
/*   Updated: 2024/09/02 17:03:58 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	eat_w(char *string)
{
	int	i;

	i = 0;
	while (string[i] == '\t' || string[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	calc_color(t_game *data, char type)
{
	if (data->r > 255 || data->g > 255 || data->b > 255)
		return (1);
	if (type == 'C')
		data->color_ceiling = ((data->r << 16) | (data->g << 8) | data->b);
	if (type == 'F')
		data->color_floor = ((data->r << 16) | (data->g << 8) | data->b);
	return (0);
}

void	bruh(t_game *data, int *le, char *numba)
{
	int	zahl;

	zahl = ft_atoi(numba);
	if (*le == 0)
		data->r = zahl;
	if (*le == 1)
		data->g = zahl;
	if (*le == 2)
		data->b = zahl;
	*le = *le + 1;
}

int	color_hex(t_game *data, char *line, char type, int i)
{
	char	numba[6];
	int		xd;
	int		le;

	xd = 0;
	le = 0;
	while (line[i])
	{
		if (line[i] == ',' || line[i] == '\n')
		{
			bruh(data, &le, numba);
			xd = 0;
		}
		else
		{
			numba[xd] = line[i];
			xd++;
			numba[xd] = '\0';
		}
		if (line[i] == '\n')
			break ;
		i++;
	}
	return (calc_color(data, type));
}

int	parse_color(t_game *data, char *line, char type, int i)
{
	int		le;
	int		xd;

	le = 0;
	xd = 0;
	while (le != 3)
	{
		while (line[i] == ' ')
			i++;
		if ((line[i] > 57 || line[i] < 48) && (line[i] != ','
				&& line[i] != '\n'))
			return (1);
		xd++;
		if (line[i] == ',' || line[i] == '\n')
		{
			if (xd > 4 || xd == 1)
				return (1);
			xd = 0;
			le++;
		}
		i++;
	}
	if (line[i - 1] != '\n')
		return (1);
	return (color_hex(data, line, type, 0));
}
