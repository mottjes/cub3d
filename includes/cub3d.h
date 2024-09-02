/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:57:51 by mottjes           #+#    #+#             */
/*   Updated: 2024/09/02 18:03:49 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define SCREEN_WIDTH 	1920
# define SCREEN_HEIGHT  1080

# define MOVE_SPEED      0.5
# define ROT_SPEED       0.2
# define FOV             0.66

# define KEY_ESC         65307
# define KEY_W           119
# define KEY_A           97
# define KEY_S           115
# define KEY_D           100
# define KEY_LEFT        65361
# define KEY_RIGHT       65363

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_ray
{
	double	camera_x;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_tex
{
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		pos;
	int		color;
}	t_tex;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}	t_player;

typedef struct s_texture
{
	char	*path;
	t_img	img;
	int		height;
	int		width;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_player	player;
	t_ray		ray;
	t_tex		tex;
	t_img		*frame;
	t_texture	texture_no;
	t_texture	texture_so;
	t_texture	texture_ea;
	t_texture	texture_we;
	char		**map;
	int			map_widht;
	int			map_height;
	int			color_ceiling;
	int			color_floor;
	int			r;
	int			g;
	int			b;
}	t_game;

//      init.c
void		init_mlx(t_game *game);
void		init_ray(t_ray *ray, t_player *player);

//      key_hook.c
int			key_hook(int keysym, t_game *game);

//      render.c
void		render(t_game *game);

//      calculations.c
double		ft_abs(double nbr);
void		set_ray(t_game *game, t_ray *ray, int x);
void		calculate_side_dist(t_game *game, t_ray *ray);
void		dda(t_game *game, t_ray *ray);
void		calculate_line_height(t_ray *ray);

//      texture.c
void		my_pixel_put(t_img *frame, int x, int y, int color);
t_texture	*choose_texture(t_game *game);
void		load_textures(t_game *game);

//      minimap.c
void		render_minimap(t_game *game);

//      exit.c
void		free_all(t_game *game);
int			exit_game(t_game *game);

//      parser.c
int			cub_parser(char *path, t_game *data, int error);
int			parse_prep(int fd_path, t_game *data, char *path, int error);
int			parse_settings(int fd_path, t_game *data, char *line, int e);
char		*line2tex(char *line);
char		*pass_norminette(char*line, int fd_path, int *e);

//      parser_util1.c
void		floodfill_s(char **map, int x, int y, int *error);
void		player_info(t_game *data, int x, int y);
void		tidy_up_map(t_game *data, char **map, int x, int y);
void		vibe_check(char **map, int x, int y, int *error);
int			funfill(char **map, t_game *data, int x, int y);

//      parser_util2.c
int			outerfill(char **map, t_game *data, int x, int y);
int			map_sizes(char **map, t_game *data, int wi, int l);
void		row_ws(char **map, int y);
char		**map_gen(char **map, t_game *data, char *line, int fd_path);
int			settings_set(int fd_path, t_game *data, char *line);

//      parser_util3.c
int			eat_w(char *string);
int			calc_color(t_game *data, char type);
void		bruh(t_game *data, int *le, char *numba);
int			color_hex(t_game *data, char *line, char type, int i);
int			parse_color(t_game *data, char *line, char type, int i);

//		parser_util4.c
int			check_path(char *path);
#endif