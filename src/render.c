/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:21:56 by mottjes           #+#    #+#             */
/*   Updated: 2024/06/03 16:01:24 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

extern int	map[24][24];

void	my_pixel_put(t_img *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render_texture(int x, t_game *game)
{
	double wallX;
	int texX;
	double step;
	double texPos;
	int color; 
	int texY;

	t_texture *texture;

	if (game->ray.side)
	{
		if (game->ray.dirY < 0)
			texture = &game->texture_we;
		else
			texture = &game->texture_no;
	}
	else
	{
		if (game->ray.dirX < 0)
			texture = &game->texture_so;
		else
			texture = &game->texture_ea;
	}

	if (game->ray.side == 0) 
		wallX = game->player.posY + game->ray.perpWallDist * game->ray.dirY;
	else
		wallX = game->player.posX + game->ray.perpWallDist * game->ray.dirX;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)texture->width);
	if(game->ray.side == 0 && game->ray.dirX > 0)
		texX = texture->width - texX - 1;
	if(game->ray.side == 1 && game->ray.dirY < 0)
		texX = texture->width - texX - 1;
	step = 1.0 * texture->height / game->ray.lineHeight;
	texPos = (game->ray.drawStart - SCREEN_HEIGHT / 2 + game->ray.lineHeight / 2) * step;
	for(int y = game->ray.drawStart; y < game->ray.drawEnd; y++)
	{
		texY = (int)texPos & (texture->height - 1);
		texPos += step;
		int pos;

		pos = (texY * texture->img.line_length + texX * (texture->img.bits_per_pixel / 8));
		color = *(unsigned int *)(texture->img.addr + pos);
		if(game->ray.side == 1) 
			color = (color >> 1) & 8355711;
		my_pixel_put(game->frame, x, y, color);
	}
}

void	render_floor_ceiling(int x, t_game *game)
{
	int	y;

	y = 0;
	while (y < game->ray.drawStart && y < (SCREEN_HEIGHT / 2))
	{
		my_pixel_put(game->frame, x, y, game->color_ceiling);
		y++;
	}
	y = game->ray.drawEnd;
	while (y < SCREEN_HEIGHT && y > 0)
	{
		my_pixel_put(game->frame, x, y, game->color_floor);
		y++;
	}
}

void	render_line(int x, t_game *game, t_ray *ray)
{
	set_ray(x, game, ray);
	calculate_side_dist(game, ray);
	dda(ray);
	calculate_line_height(ray);
	render_texture(x, game);
	render_floor_ceiling(x, game);
}

void	render_mini_map(t_game *game)
{
	int x;
	int y;

	x = 100;
	while (x <= 105)
	{
		y = 100;
		while (y <= 105)
		{
			my_pixel_put(game->frame, x, y, 0xFF0000);
			y++;
		}
		x++;
	}

	x = 10;
	while (x <= 210)
	{
		y = 10;
		while (y <= 210)
		{
			if (map[(int)game->player.posX + (x - 105) / 10][(int)game->player.posY + (y - 105) / 10])
				my_pixel_put(game->frame, x, y, 0xFFFF00);
			y++;
		}
		x++;
	}
}

void	render(t_game *game)
{
	t_img	img;
	int		x;

	x = 0;
	img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	game->frame = &img;
	while (x < SCREEN_WIDTH)
	{
		render_line(x, game, &game->ray);
		x++;
	}
	render_mini_map(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, game->frame->img, 0, 0);
	mlx_destroy_image(game->mlx, game->frame->img);
	game->frame = NULL;
}
