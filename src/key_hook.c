/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:21:39 by mottjes           #+#    #+#             */
/*   Updated: 2024/06/06 15:52:21 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

extern int	map[24][24];

void	move_player_w_s(t_player *p, int dir)
{
	if (dir > 0)
	{
		if (!map[(int)(p->posX + p->dirX * (MOVE_SPEED + 0.1))][(int)p->posY])
			p->posX += p->dirX * MOVE_SPEED;
		if (!map[(int)p->posX][(int)(p->posY + p->dirY * (MOVE_SPEED + 0.1))])
			p->posY += p->dirY * MOVE_SPEED;
	}
	else if (dir < 0)
	{
		if (!map[(int)p->posX][(int)(p->posY - p->dirY * (MOVE_SPEED + 0.1))])
			p->posY -= p->dirY * MOVE_SPEED;
		if (!map[(int)(p->posX - p->dirX * (MOVE_SPEED + 0.1))][(int)p->posY])
			p->posX -= p->dirX * MOVE_SPEED;
	}
}

void	move_player_a_d(t_player *p, int dir)
{
	if (dir > 0)
	{
		if (!map[(int)(p->posX - p->dirY * (MOVE_SPEED + 0.1))][(int)p->posY])
			p->posX -= p->dirY * MOVE_SPEED;
		if (!map[(int)p->posX][(int)(p->posY + p->dirX * (MOVE_SPEED + 0.1))])
			p->posY += p->dirX * MOVE_SPEED;
	}
	else if (dir < 0)
	{
		if (!map[(int)(p->posX + p->dirY * (MOVE_SPEED + 0.2))][(int)p->posY])
			p->posX += p->dirY * MOVE_SPEED;
		if (!map[(int)p->posX][(int)(p->posY - p->dirX * (MOVE_SPEED + 0.2))])
			p->posY -= p->dirX * MOVE_SPEED;
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
		move_player_w_s(&game->player, 1);
	if (keysym == KEY_S)
		move_player_w_s(&game->player, -1);
	if (keysym == KEY_A)
		move_player_a_d(&game->player, 1);
	if (keysym == KEY_D)
		move_player_a_d(&game->player, -1);
	if (keysym == KEY_LEFT)
		rotate_player(&game->player, &game->ray, false);
	if (keysym == KEY_RIGHT)
		rotate_player(&game->player, &game->ray, true);
	render(game);
	return (0);
}
