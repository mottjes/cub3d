/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:21:39 by mottjes           #+#    #+#             */
/*   Updated: 2024/06/03 15:05:59 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

extern int	map[24][24];

void	move_player_w_s(t_game *game, int dir)
{
	if (dir > 0)
	{
		if(map[(int)(game->player.posX + game->player.dirX * MOVE_SPEED)][(int)game->player.posY] == 0) 
			game->player.posX += game->player.dirX * MOVE_SPEED;
    	if(map[(int)game->player.posX][(int)(game->player.posY + game->player.dirY * MOVE_SPEED)] == 0) 
			game->player.posY += game->player.dirY * MOVE_SPEED;
	}
	else if (dir < 0)
	{
		if(map[(int)game->player.posX][(int)(game->player.posY + game->player.dirY * MOVE_SPEED)] == 0) 
			game->player.posX -= game->player.dirX * MOVE_SPEED;
		if(map[(int)(game->player.posX + game->player.dirX * MOVE_SPEED)][(int)game->player.posY] == 0) 
			game->player.posY -= game->player.dirY * MOVE_SPEED;
	}
}

void	move_player_a_d(t_game *game, int dir)
{
	if (dir > 0)
	{
		if (map[(int)(game->player.posX -= game->player.dirY * MOVE_SPEED)][(int)game->player.posY] == 0)
			game->player.posX -= game->player.dirY * MOVE_SPEED;
    	if(map[(int)game->player.posX][(int)(game->player.posY += game->player.dirX * MOVE_SPEED * MOVE_SPEED)] == 0) 
			game->player.posY += game->player.dirX * MOVE_SPEED;
	}
	else if (dir < 0)
	{
		if (map[(int)(game->player.posX -= game->player.dirY * MOVE_SPEED)][(int)game->player.posY] == 0)
			game->player.posX += game->player.dirY * MOVE_SPEED;
    	if(map[(int)game->player.posX][(int)(game->player.posY += game->player.dirX * MOVE_SPEED * MOVE_SPEED)] == 0) 
			game->player.posY -= game->player.dirX * MOVE_SPEED;
	}
}

void	rotate_player(t_player *p, t_ray *r, bool clockwise)
{
	double	olddirx;
	double	oldplanex;

	if (clockwise)
	{
		olddirx = p->dirX;
		p->dirX = p->dirX * cos(-ROT_SPEED) - p->dirY * sin(-ROT_SPEED);
		p->dirY = olddirx * sin(-ROT_SPEED) + p->dirY * cos(-ROT_SPEED);
		oldplanex = r->planeX;
		r->planeX = r->planeX * cos(-ROT_SPEED) - r->planeY * sin(-ROT_SPEED);
		r->planeY = oldplanex * sin(-ROT_SPEED) + r->planeY * cos(-ROT_SPEED);
	}
	else
	{
		olddirx = p->dirX;
		p->dirX = p->dirX * cos(ROT_SPEED) - p->dirY * sin(ROT_SPEED);
		p->dirY = olddirx * sin(ROT_SPEED) + p->dirY * cos(ROT_SPEED);
		oldplanex = r->planeX;
		r->planeX = r->planeX * cos(ROT_SPEED) - r->planeY * sin(ROT_SPEED);
		r->planeY = oldplanex * sin(ROT_SPEED) + r->planeY * cos(ROT_SPEED);
	}
}

int	key_hook(int keysym, t_game *game)
{
	if (keysym == KEY_ESC)
		exit_game(game);
	if (keysym == KEY_W)
		move_player_w_s(game, 1);
	if (keysym == KEY_S)
		move_player_w_s(game, -1);
	if (keysym == KEY_A)
		move_player_a_d(game, 1);
	if (keysym == KEY_D)
		move_player_a_d(game, -1);
	if (keysym == KEY_LEFT)
		rotate_player(&game->player, &game->ray, false);
	if (keysym == KEY_RIGHT)
		rotate_player(&game->player, &game->ray, true);
	render(game);
	return (0);
}
