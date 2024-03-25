# include "../includes/cub3d.h"

void    init_game(t_game *game, t_player *player, t_ray *ray)
{
    //game initialization
    game->player = player;
    game->ray = ray;
    game->mlx = mlx_init();
    game->window = mlx_new_window(game->mlx, screenWidth, screenHeight, "cub3d");
    //player initialization
    player->posX = 6;
    player->posY = 3;
    player->dirX = 1;
    player->dirY = 0;
    //ray initialization
    ray->dirX = player->dirX;
    ray->dirY = player->dirY;
    ray->planeX = 0;
    ray->planeY = 0.66;
}

double ft_abs(double nbr)
{
    if (nbr < 0)
        nbr *= -1;
    return (nbr);
}

void    draw_vertical_line(t_game *game, int x, int color)
{
    int y;

    if (game->ray->side)
    {
        if (color == 0xFF0000)
            color = 0xDD0000;
        if (color == 0x00FF00)
            color = 0x00DD00;
        if (color == 0x0000FF)
            color = 0x0000DD;
    }
    y = game->ray->drawStart;
    while (y < game->ray->drawEnd)
    {
        mlx_pixel_put(game->mlx, game->window, x, y, color);
        y++;
    }
}

void    render(t_game *game, t_ray *ray)
{
    int color;
    int x;
    
    x = 0;
    while (x < screenWidth)
    {
        ray->cameraX = 2 * x / (double)screenHeight - 1;
        ray->dirX = game->player->dirX + ray->planeX * ray->cameraX;
        ray->dirY = game->player->dirY + ray->planeY * ray->cameraX;

        //calcutalting the distance the ray has to travel to do one x or y step
        if (ray->dirX == 0)
            ray->dirX = 0.00001;
        ray->deltaDistX =  ft_abs(1 / ray->dirX);
        if (ray->dirY == 0)
            ray->dirY = 0.00001;
        ray->deltaDistY = ft_abs(1 / ray->dirY);
        //in which box of the map we are in
        ray->mapX = (int)game->player->posX;
        ray->mapY = (int)game->player->posY;

        //set hit flag to 0
        ray->hit = 0;

        //calulate step abd initial sideDist
        if (ray->dirX < 0)
        {
            ray->stepX = -1;
            ray->sideDistX = (game->player->posX - ray->mapX) * ray->deltaDistX;
        }
        else
        {
            ray->stepX = 1;
            ray->sideDistX = (ray->mapX + 1 - game->player->posX) * ray->deltaDistX;
        }
        if (ray->dirY < 0)
        {
            ray->stepY = -1;
            ray->sideDistY = (game->player->posY - ray->mapY) * ray->deltaDistY;
        }
        else
        {
            ray->stepY = 1;
            ray->sideDistY = (ray->mapY + 1 - game->player->posY) * ray->deltaDistY;
        }

        //perform DDA
        while (ray->hit == 0)
        {
            //jumps to the next map-grid intersection
            if (ray->sideDistX < ray->sideDistY)
            {
                ray->sideDistX += ray->deltaDistX;
                ray->mapX += ray->stepX;
                ray->side = 0;
            }
            else
            {
                ray->sideDistY += ray->deltaDistY;
                ray->mapY += ray->stepY;
                ray->side = 1;
            }
            //check if ray hits wall
            if (map[ray->mapX][ray->mapY] > 0)
            {
                ray->hit = 1;
                if (map[ray->mapX][ray->mapY] == 1)
                    color = 0xFF0000;
                else if (map[ray->mapX][ray->mapY] == 2)
                    color = 0x00FF00;
                else if (map[ray->mapX][ray->mapY] == 3)
                    color = 0x0000FF;
                else if (map[ray->mapX][ray->mapY] == 4)
                    color = 0xFF0000;
            }
               
        }
        //set wall to player distance 
        if (ray->side == 0)
            ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
        else
            ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);

        //calulate line height
        ray->lineHeight = (int)(screenHeight / ray->perpWallDist);
        ray->drawStart = - ray->lineHeight / 2 + screenHeight / 2;
        if (ray->drawStart < 0)
            ray->drawStart = 0;
        ray->drawEnd = ray->lineHeight / 2 + screenHeight / 2;
        if (ray->drawEnd >= screenHeight)
            ray->drawEnd = screenHeight - 1;

        draw_vertical_line(game, x, color);
        x++;
    }
}

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
        game->player->posX -= game->player->dirX * moveSpeed;
        game->player->posY -= game->player->dirY * moveSpeed;
    }
    if (keysym == KEY_S)
    {
        game->player->posX += game->player->dirX * moveSpeed;
        game->player->posY += game->player->dirY * moveSpeed;
    }
    //not working correctly
    // if (keysym == KEY_A)
    // {
    //     game->player->posX -= game->player->dirX * cos(1.571) - game->player->dirY * sin(1.571) * moveSpeed;
    //     game->player->posY -= game->player->dirX * sin(1.571) + game->player->dirY * cos(1.571) * moveSpeed;
    // }
    // if (keysym == KEY_D)
    // {
    //     game->player->posX += game->player->dirX * cos(1.571) - game->player->dirY * sin(1.571) * moveSpeed;
    //     game->player->posY += game->player->dirX * sin(1.571) + game->player->dirY * cos(1.571) * moveSpeed;
    // }
    if (keysym == KEY_LEFT)
    {
        oldDirX = game->player->dirX;
        game->player->dirX = game->player->dirX * cos(-rotSpeed) - game->player->dirY * sin(-rotSpeed);
        game->player->dirY = oldDirX * sin(-rotSpeed) + game->player->dirY * cos(-rotSpeed);
        oldPlaneX = game->ray->planeX;
        game->ray->planeX = game->ray->planeX * cos(-rotSpeed) - game->ray->planeY * sin(-rotSpeed);
        game->ray->planeY = oldPlaneX * sin(-rotSpeed) + game->ray->planeY * cos(-rotSpeed);
    }
    if (keysym == KEY_RIGHT)
    {
        oldDirX = game->player->dirX;
        game->player->dirX = game->player->dirX * cos(rotSpeed) - game->player->dirY * sin(rotSpeed);
        game->player->dirY = oldDirX * sin(rotSpeed) + game->player->dirY * cos(rotSpeed);
        oldPlaneX = game->ray->planeX;
        game->ray->planeX = game->ray->planeX * cos(rotSpeed) - game->ray->planeY * sin(rotSpeed);
        game->ray->planeY = oldPlaneX * sin(rotSpeed) + game->ray->planeY * cos(rotSpeed);
    }
    mlx_clear_window(game->mlx, game->window);
    render(game, game->ray);
    return 0;
}

int main(void)
{
    t_game      game;
    t_player    player;
    t_ray       ray;
    
    init_game(&game, &player, &ray);
    render(&game, &ray);
    mlx_hook(game.window, 2, 1L<<0, key_hook, &game);
    mlx_loop(game.mlx);
}   
