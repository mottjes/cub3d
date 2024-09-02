/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:22:10 by mottjes           #+#    #+#             */
/*   Updated: 2024/09/02 13:18:25 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_pixel_put(t_img *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length
			+ x * (frame->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_texture	*choose_texture(t_game *game)
{
	if (game->ray.side)
	{
		if (game->ray.dir_y < 0)
			return (&game->texture_we);
		else
			return (&game->texture_no);
	}
	else
	{
		if (game->ray.dir_x < 0)
			return (&game->texture_so);
		else
			return (&game->texture_ea);
	}
}

void	create_img(t_game *game, t_texture *texture)
{
	texture->img.img = mlx_xpm_file_to_image(game->mlx,
			texture->path, &texture->width, &texture->height);
	if (!texture->img.img)
	{
		printf("Error: Could not load texture\n");
		exit_game(game);
	}
	texture->img.addr = mlx_get_data_addr(texture->img.img,
			&texture->img.bits_per_pixel,
			&texture->img.line_length,
			&texture->img.endian);
}

void	load_textures(t_game *game)
{
	create_img(game, &game->texture_no);
	create_img(game, &game->texture_so);
	create_img(game, &game->texture_ea);
	create_img(game, &game->texture_we);
}
