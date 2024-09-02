/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:22:01 by mottjes           #+#    #+#             */
/*   Updated: 2024/09/02 17:33:16 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

void	free_all(t_game *game)
{
	if (game->texture_no.path)
		free(game->texture_no.path);
	if (game->texture_so.path)
		free(game->texture_so.path);
	if (game->texture_we.path)
		free(game->texture_we.path);
	if (game->texture_ea.path)
		free(game->texture_ea.path);
	free_map(game);
	if (game->texture_no.img.img)
		mlx_destroy_image(game->mlx, game->texture_no.img.img);
	if (game->texture_so.img.img)
		mlx_destroy_image(game->mlx, game->texture_so.img.img);
	if (game->texture_we.img.img)
		mlx_destroy_image(game->mlx, game->texture_we.img.img);
	if (game->texture_ea.img.img)
		mlx_destroy_image(game->mlx, game->texture_ea.img.img);
	if (game->window && game->mlx)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
}

int	exit_game(t_game *game)
{
	free_all(game);
	exit(0);
}
