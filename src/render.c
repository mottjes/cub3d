/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:21:56 by mottjes           #+#    #+#             */
/*   Updated: 2024/09/02 14:37:51 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_texture_line_2(t_game *game, t_texture *texture, int x)
{
	t_tex	*tex;
	int		y;

	tex = &game->tex;
	y = game->ray.draw_start;
	while (y < game->ray.draw_end)
	{
		tex->tex_y = (int)tex->tex_pos;
		tex->tex_pos += tex->step;
		tex->pos = (tex->tex_y * texture->img.line_length + tex->tex_x
				* (texture->img.bits_per_pixel / 8));
		tex->color = *(unsigned int *)(texture->img.addr + tex->pos);
		if (game->ray.side == 1)
			tex->color = (tex->color >> 1) & 8355711;
		my_pixel_put(game->frame, x, y, tex->color);
		y++;
	}
}

void	render_texture_line(t_game *game, t_ray *ray, int x)
{
	t_texture	*texture;
	t_tex		*tex;

	tex = &game->tex;
	texture = choose_texture(game);
	if (ray->side == 0)
		tex->wall_x = game->player.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		tex->wall_x = game->player.pos_x + ray->perp_wall_dist * ray->dir_x;
	tex->wall_x -= floor(tex->wall_x);
	tex->tex_x = (int)(tex->wall_x * (double)texture->width);
	if (ray->side == 0 && ray->dir_x > 0)
		tex->tex_x = texture->width - tex->tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		tex->tex_x = texture->width - tex->tex_x - 1;
	tex->step = 1.0 * texture->height / ray->line_height;
	tex->tex_pos = (ray->draw_start - SCREEN_HEIGHT / 2.0
			+ ray->line_height / 2.0) * tex->step;
	render_texture_line_2(game, texture, x);
}

void	render_floor_ceiling(t_game *game, int x)
{
	int	y;

	y = 0;
	while (y < game->ray.draw_start && y < (SCREEN_HEIGHT / 2))
	{
		my_pixel_put(game->frame, x, y, game->color_ceiling);
		y++;
	}
	y = game->ray.draw_end;
	while (y < SCREEN_HEIGHT && y > 0)
	{
		my_pixel_put(game->frame, x, y, game->color_floor);
		y++;
	}
}

void	render_line(int x, t_game *game, t_ray *ray)
{
	set_ray(game, ray, x);
	calculate_side_dist(game, ray);
	dda(game, ray);
	calculate_line_height(ray);
	render_texture_line(game, ray, x);
	render_floor_ceiling(game, x);
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
