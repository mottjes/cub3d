#include "../includes/cub3d.h"

extern int map[24][24];

int    key_hook(int keysym, t_game *game)
{   
    double oldDirX;
    double oldPlaneX;

    if (keysym == KEY_ESC)
    {
        mlx_destroy_display(game->mlx);
        mlx_destroy_window(game->mlx, game->window);
        exit(0);
    }
    if (keysym == KEY_W)
    {
        game->player->posX -= game->player->dirX * MOVE_SPEED;
        game->player->posY -= game->player->dirY * MOVE_SPEED;
    }
    if (keysym == KEY_S)
    {
        game->player->posX += game->player->dirX * MOVE_SPEED;
        game->player->posY += game->player->dirY * MOVE_SPEED;
    }
    if (keysym == KEY_LEFT)
    {
        oldDirX = game->player->dirX;
        game->player->dirX = game->player->dirX * cos(-ROT_SPEED) - game->player->dirY * sin(-ROT_SPEED);
        game->player->dirY = oldDirX * sin(-ROT_SPEED) + game->player->dirY * cos(-ROT_SPEED);
        oldPlaneX = game->ray->planeX;
        game->ray->planeX = game->ray->planeX * cos(-ROT_SPEED) - game->ray->planeY * sin(-ROT_SPEED);
        game->ray->planeY = oldPlaneX * sin(-ROT_SPEED) + game->ray->planeY * cos(-ROT_SPEED);
    }
    if (keysym == KEY_RIGHT)
    {
        oldDirX = game->player->dirX;
        game->player->dirX = game->player->dirX * cos(ROT_SPEED) - game->player->dirY * sin(ROT_SPEED);
        game->player->dirY = oldDirX * sin(ROT_SPEED) + game->player->dirY * cos(ROT_SPEED);
        oldPlaneX = game->ray->planeX;
        game->ray->planeX = game->ray->planeX * cos(ROT_SPEED) - game->ray->planeY * sin(ROT_SPEED);
        game->ray->planeY = oldPlaneX * sin(ROT_SPEED) + game->ray->planeY * cos(ROT_SPEED);
    }
    render(game, game->ray);
    return 0;
}

int    exit_game(t_game *game)
{
    mlx_destroy_display(game->mlx);
    mlx_destroy_window(game->mlx, game->window);
    exit(0);
    return (0);
}
