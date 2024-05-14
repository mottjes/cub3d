#include "../includes/cub3d.h"

extern int map[24][24];

double ft_abs(double nbr)
{
    if (nbr < 0)
        nbr *= -1;
    return (nbr);
}

void    my_pixel_put(t_game *game, int x, int y, int color)
{
    char    *dst;

    dst = game->img->addr + (y * game->img->line_length + x * (game->img->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
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
        my_pixel_put(game, x, y, color);
        // mlx_pixel_put(game->mlx, game->window, x, y, color);
        y++;
    }
}

void    render(t_game *game, t_ray *ray)
{
    t_img       img;
    // int         color;
    int         x;
    
	int buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	int texture[16384];

	// for(int x = 0; x < texWidth; x++)
	// {
	// 	for(int y = 0; y < texHeight; y++)
  	// 	{
    // // int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
    // // //int xcolor = x * 256 / texWidth;
    // // int ycolor = y * 256 / texHeight;
    // // int xycolor = y * 128 / texHeight + x * 128 / texWidth;
    // // texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
    // // texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
    // // texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
    // // texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
    // // texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
    // texture[texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    // // texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
    // // texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
  	// 	}
	// }


	t_img	img2;
	char	*relative_path = "./shrader.xpm";
	int		img_width;
	int		img_height;

	img2.img = mlx_xpm_file_to_image(game->mlx, relative_path, &img_width, &img_height);
	char *mlx_data_addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel, &img2.line_length, &img2.endian);
	for (int x = 0; x < img_width; x++)
	{
		for (int y = 0; y < img_height; y++)
		{
			int pos = (y * img2.line_length + x * (img2.bits_per_pixel / 8));
			texture[texWidth * y + x] = *(unsigned int *)(mlx_data_addr + pos);
		}
	}

	


    x = 0;
    img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    game->img = &img;
    while (x < SCREEN_WIDTH)
    {
        ray->cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
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
                // if (map[ray->mapX][ray->mapY] == 1)
                //     color = 0xFF0000;
                // else if (map[ray->mapX][ray->mapY] == 2)
                //     color = 0x00FF00;
                // else if (map[ray->mapX][ray->mapY] == 3)
                //     color = 0x0000FF;
                // else if (map[ray->mapX][ray->mapY] == 4)
                //     color = 0xFF0000;
            }     
        }
        //set wall to player distance 
        if (ray->side == 0)
            ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);
        else
            ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);

        //calulate line height
        ray->lineHeight = (int)(SCREEN_HEIGHT / ray->perpWallDist);
        ray->drawStart = - ray->lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (ray->drawStart < 0)
            ray->drawStart = 0;
        ray->drawEnd = ray->lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (ray->drawEnd >= SCREEN_HEIGHT)
            ray->drawEnd = SCREEN_HEIGHT - 1;
        
        // draw_vertical_line(game, x, color);

      //calculate value of wallX
      double wallX; //where exactly the wall was hit
      if (game->ray->side == 0) wallX = game->player->posY + game->ray->perpWallDist * game->ray->dirY;
      else           wallX = game->player->posX + game->ray->perpWallDist * game->ray->dirX;
      wallX -= floor((wallX));

      //x coordinate on the texture
      int texX = (int)(wallX * (double)texWidth);
      if(game->ray->side == 0 && game->ray->dirX > 0) texX = texWidth - texX - 1;
      if(game->ray->side == 1 && game->ray->dirY < 0) texX = texWidth - texX - 1;

	 double step = 1.0 * texHeight / game->ray->lineHeight;
      // Starting texture coordinate
      double texPos = (game->ray->drawStart - SCREEN_HEIGHT / 2 + game->ray->lineHeight / 2) * step;
      for(int y = game->ray->drawStart; y < game->ray->drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        int color = texture[texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(game->ray->side == 1) color = (color >> 1) & 8355711;
        buffer[y][x] = color;
   		}


        x++;
    }

	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			my_pixel_put(game, x, y, buffer[y][x]);
		}
	}

    for(int y = 0; y < SCREEN_HEIGHT; y++) for(int x = 0; x < SCREEN_WIDTH; x++) buffer[y][x] = 0; //clear the buffer instead of cls()





    mlx_clear_window(game->mlx, game->window);
    mlx_put_image_to_window(game->mlx, game->window, game->img->img, 0, 0);
    game->img = NULL;
}
