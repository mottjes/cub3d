/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:08:28 by mottjes           #+#    #+#             */
/*   Updated: 2024/05/23 13:12:20 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

extern int	map[24][24];

double	ft_abs(double nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

void	set_ray(int x, t_game *game, t_ray *ray)
{
	ray->cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->dirX = game->player.dirX + ray->planeX * ray->cameraX;
	ray->dirY = game->player.dirY + ray->planeY * ray->cameraX;
	if (ray->dirX == 0)
		ray->dirX = 0.00001;
	ray->deltaDistX = ft_abs(1 / ray->dirX);
	if (ray->dirY == 0)
		ray->dirY = 0.00001;
	ray->deltaDistY = ft_abs(1 / ray->dirY);
	ray->mapX = (int)game->player.posX;
	ray->mapY = (int)game->player.posY;
	ray->hit = 0;
}

void	calculate_side_dist(t_game *game, t_ray *ray)
{
	if (ray->dirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (game->player.posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1 - game->player.posX) * ray->deltaDistX;
	}
	if (ray->dirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (game->player.posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1 - game->player.posY) * ray->deltaDistY;
	}
}

void	dda(t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (map[ray->mapX][ray->mapY] != 0)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
	else
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);
}

void	calculate_line_height(t_ray *ray)
{
	ray->lineHeight = (int)(SCREEN_HEIGHT / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (ray->drawEnd >= SCREEN_HEIGHT)
		ray->drawEnd = SCREEN_HEIGHT - 1;
}
