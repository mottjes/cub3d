#ifndef CUB3D_H
#define	CUB3D_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

#define SCREEN_WIDTH 	1920
#define	SCREEN_HEIGHT  	1080

#define MOVE_SPEED      0.45
#define ROT_SPEED       0.2
#define FOV             0.66

#define KEY_ESC         65307
#define KEY_W           119
#define KEY_A           97
#define KEY_S           115
#define KEY_D           100
#define KEY_LEFT        65361
#define KEY_RIGHT       65363

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}       t_img;

typedef struct s_ray
{
    double  cameraX;
    double  planeX;
    double  planeY;
    double  dirX;
    double  dirY;
    double  deltaDistX;
    double  deltaDistY;
    double  sideDistX;
    double  sideDistY;
    double  perpWallDist;
    int     mapX;
    int     mapY;
    int     stepX;
    int     stepY;
    int     hit;
    int     side;
    int     lineHeight;
    int     drawStart;
    int     drawEnd;
}   t_ray;

typedef struct s_player
{
    double  posX;
    double  posY;
    double  dirX;
    double  dirY;
}   t_player;

typedef struct s_texture
{
    char     *path;
    t_img    img;
    int      height;
    int      width;
}       t_texture;

typedef struct s_game
{
    void        *mlx;
    void        *window;
    t_player    player;
    t_ray       ray;
    t_img       *frame;
    t_texture   texture_no;
    t_texture   texture_so;
    t_texture   texture_ea;
    t_texture   texture_we;
    int         **map;
    int         color_ceiling;
    int         color_floor;
}       t_game;

//      init.c
void    init_mlx(t_game *game);
void    init_ray(t_ray *ray, t_player *player);

//      key_hook.c
int    key_hook(int keysym, t_game *game);

//      render.c
void    render(t_game *game);

//      calculations.c
double	ft_abs(double nbr);
void	set_ray(int x, t_game *game, t_ray *ray);
void	calculate_side_dist(t_game *game, t_ray *ray);
void	dda(t_ray *ray);
void    calculate_line_height(t_ray *ray);

//      texture.c
void    load_textures(t_game *game);

//      exit.c
void    free_all(t_game *game);
int    exit_game(t_game *game);

#endif
