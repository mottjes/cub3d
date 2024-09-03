/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:21:52 by mottjes           #+#    #+#             */
/*   Updated: 2024/09/03 15:16:08 by mottjes          ###   ########.fr       */
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
	ray->dir_x = player->dir_x;
	ray->dir_y = player->dir_y;
	ray->plane_x = ray->dir_y * -FOV;
	ray->plane_y = ray->dir_x * FOV;
}
