#include "../includes/cub3d.h"

extern int map[24][24];

void    init_mlx(t_game *game)
{
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
}

void    init_player(t_player *player)
{
    player->posX = 6;
    player->posY = 3;
    player->dirX = 1;
    player->dirY = 0;
}

void    init_ray(t_ray *ray, t_player *player)
{
    ray->dirX = player->dirX;
    ray->dirY = player->dirY;
    ray->planeX = 0;
    ray->planeY = 0.66;
}

void    init_game(t_game *game, t_player *player, t_ray *ray)
{
    game->player = player;
    game->ray = ray;
    init_mlx(game);
    init_player(player);
    init_ray(ray, player);
}
