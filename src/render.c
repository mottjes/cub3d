/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:21:56 by mottjes           #+#    #+#             */
/*   Updated: 2024/06/06 16:39:14 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

extern int	map[24][24];

void	my_pixel_put(t_img *frame, int x, int y, int color)
{
	char	*dst;

	dst = frame->addr + (y * frame->line_length
			+ x * (frame->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_texture(int x, t_game *game)
{
	t_texture	*texture;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			color;

	texture = choose_texture(game);
	if (game->ray.side == 0)
		wall_x = game->player.posY + game->ray.perpWallDist * game->ray.dirY;
	else
		wall_x = game->player.posX + game->ray.perpWallDist * game->ray.dirX;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)texture->width);
	if (game->ray.side == 0 && game->ray.dirX > 0)
		tex_x = texture->width - tex_x - 1;
	if (game->ray.side == 1 && game->ray.dirY < 0)
		tex_x = texture->width - tex_x - 1;
	step = 1.0 * texture->height / game->ray.lineHeight;
	tex_pos = (game->ray.drawStart - SCREEN_HEIGHT / 2.0 + game->ray.lineHeight / 2.0) * step;
	for (int y = game->ray.drawStart; y < game->ray.drawEnd; y++)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		int	pos;

		pos = (tex_y * texture->img.line_length + tex_x * (texture->img.bits_per_pixel / 8));
		color = *(unsigned int *)(texture->img.addr + pos);
		if (game->ray.side == 1)
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
	render_minimap(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_put_image_to_window(game->mlx, game->window, game->frame->img, 0, 0);
	mlx_destroy_image(game->mlx, game->frame->img);
	game->frame = NULL;
}
