/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:51:19 by mottjes           #+#    #+#             */
/*   Updated: 2024/08/28 17:46:21 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

extern int	map[24][24];

void	render_sqare(t_game *game, int x, int y)
{
	int	a;
	int	b;

	a = 0;
	while (a < 10)
	{
		b = 0;
		while (b < 10)
		{
			my_pixel_put(game->frame, x * 10 + a, y * 10 + b, 0xFFFFFF);
			b++;
		}
		a++;
	}
}

void	render_outline(t_game *game)
{
	int	i;

	i = 0;
	while (i < 200)
	{
		my_pixel_put(game->frame, i, 0, 0xFFFFFF);
		my_pixel_put(game->frame, i, 200, 0xFFFFFF);
		i++;
	}
	i = 0;
	while (i < 200)
	{
		my_pixel_put(game->frame, 0, i, 0xFFFFFF);
		my_pixel_put(game->frame, 200, i, 0xFFFFFF);
		i++;
	}
}

void	render_player(t_game *game)
{
	int	x;
	int	y;

	x = 99;
	while (x < 102)
	{
		y = 99;
		while (y < 102)
		{
			my_pixel_put(game->frame, x, y, 0xFF0000);
			y++;
		}
		x++;
	}
}

void	check_for_wall(t_game *game, t_player *p, int x, int y)
{
	if (((int)p->pos_x + x - 10 >= 0))
	{
		if (((int)p->pos_x + x - 10 < game->map_widht))
		{
			if (((int)(p->pos_y) + y - 10) >= 0)
			{
				if (((int)(p->pos_y) + y - 10) < game->map_height)
				{
					if (map[(int)(p->pos_x) + x - 10][(int)(p->pos_y) + y - 10])
						render_sqare(game, x, y);
					return ;
				}
			}
		}
	}
	render_sqare(game, x, y);
}

void	render_minimap(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < 20)
	{
		y = 0;
		while (y < 20)
		{
			check_for_wall(game, &game->player, x, y);
			y++;
		}
		x++;
	}
	render_outline(game);
	render_player(game);
}
