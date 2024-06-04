/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:51:19 by mottjes           #+#    #+#             */
/*   Updated: 2024/06/04 16:55:29 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

extern int	map[24][24];

void	render_sqare(t_game *game, int x, int y)
{
	int a;
	int b;

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

void    render_outline(t_game *game)
{
    int i;
    
    i = 0;
	while (i < 200)
	{
		my_pixel_put(game->frame, i, 0, 0xFFFF00);
		my_pixel_put(game->frame, i, 200, 0xFFFF00);
		i++;
	}
	i = 0;
	while (i < 200)
	{
		my_pixel_put(game->frame, 0, i, 0xFFFF00);
		my_pixel_put(game->frame, 200, i, 0xFFFF00);
		i++;
	}
}

void    render_player(t_game *game)
{
    int x;
    int y;

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

void	render_minimap(t_game *game)
{
	int	mapX;
	int	mapY;
	int x;
	int y;
	
    mapX = floor(game->player.posX);
	mapY = floor(game->player.posY);
	x = 0;
	while (x < 20)
	{
		y = 0;
		while (y < 20)
		{
			if ((mapX + x - 10) >= 0 && (mapX + x - 10) < 24)
			{
				if ((mapY + y - 10) >= 0 && (mapY + y - 10) < 24)
				{
					if (map[mapX + x - 10][mapY + y - 10])
						render_sqare(game, x, y);
				}
                else
                    render_sqare(game, x, y);
			}
            else
                    render_sqare(game, x, y);
			y++;
		}
		x++;
	}
    render_outline(game);
    render_player(game);
}
