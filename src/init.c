/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:21:52 by mottjes           #+#    #+#             */
/*   Updated: 2024/05/23 12:59:05 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "cub3d");
}

void	init_ray(t_ray *ray, t_player *player)
{
	ray->dirX = player->dirX;
	ray->dirY = player->dirY;
	ray->planeX = ray->dirY * FOV;
	ray->planeY = ray->dirX * -FOV;
}
