/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:22:01 by mottjes           #+#    #+#             */
/*   Updated: 2024/05/23 12:38:24 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_all(t_game *game)
{
	if (game->texture_no.img.img)
		mlx_destroy_image(game->mlx, game->texture_no.img.img);
	if (game->texture_so.img.img)
		mlx_destroy_image(game->mlx, game->texture_so.img.img);
	if (game->texture_we.img.img)
		mlx_destroy_image(game->mlx, game->texture_we.img.img);
	if (game->texture_ea.img.img)
		mlx_destroy_image(game->mlx, game->texture_ea.img.img);
	mlx_destroy_display(game->mlx);
	mlx_destroy_window(game->mlx, game->window);
}

int	exit_game(t_game *game)
{
	free_all(game);
	exit(0);
}
