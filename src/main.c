/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:21:46 by mottjes           #+#    #+#             */
/*   Updated: 2024/09/02 17:37:37 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
	{
		printf("Error: wrong input './cub3d <map.cub> \n");
		exit(1);
	}
	if (cub_parser(argv[1], &game, 0))
	{
		exit_game(&game);
	}
	init_mlx(&game);
	init_ray(&game.ray, &game.player);
	load_textures(&game);
	render(&game);
	mlx_hook(game.window, 2, (1L << 0), key_hook, &game);
	mlx_hook(game.window, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	exit_game(&game);
}
