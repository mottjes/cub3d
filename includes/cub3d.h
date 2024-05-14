#ifndef CUB3D_H
#define	CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

#define SCREEN_WIDTH 	1920
#define	SCREEN_HEIGHT  	1080
#define MOVE_SPEED      0.5
#define ROT_SPEED       0.2
#define KEY_ESC         65307
#define KEY_W           115
#define KEY_S           119
#define KEY_A           97
#define KEY_D           100
#define KEY_RIGHT       65363
#define KEY_LEFT        65361

#define texWidth        128
#define texHeight       128

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

typedef struct s_game
{
    void        *mlx;
    void        *window;
    t_player    *player;
    t_ray       *ray;
    t_img       *img;
    char        **map;
}       t_game;

// 	init.c
void    init_mlx(t_game *game);
void    init_player(t_player *player);
void    init_ray(t_ray *ray, t_player *player);
void    init_game(t_game *game, t_player *player, t_ray *ray);

// 	key_hook.c
int    exit_game(t_game *game);
int    key_hook(int keysym, t_game *game);

// 	render.c
double ft_abs(double nbr);
void    my_pixel_put(t_game *game, int x, int y, int color);
void    draw_vertical_line(t_game *game, int x, int color);
void    render(t_game *game, t_ray *ray);

#endif
