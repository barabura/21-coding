/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:10:38 by baura             #+#    #+#             */
/*   Updated: 2022/07/08 12:40:05 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*init(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		free(game);
		error_message("Map memory allocation error");
	}
	return (game);
}

void	init_game(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->player = 0;
	game->colletctible = 0;
	game->exit = 0;
	game->steps = 0;
	game->img_size = 100;
	game->img_h = 0;
	game->img_w = 0;
}

void	init_images(t_game *game)
{
	game->empty_space_img = mlx_xpm_file_to_image(game->mlx, \
	"./imgs/background.xpm", &game->img_w, &game->img_h);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, \
	"./imgs/wall.xpm", &game->img_w, &game->img_h);
	game->player_img = mlx_xpm_file_to_image(game->mlx, \
	"./imgs/cat_1.xpm", &game->img_w, &game->img_h);
	game->collectable_img = mlx_xpm_file_to_image(game->mlx, \
	"./imgs/coin_1.xpm", &game->img_w, &game->img_h);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, \
	"./imgs/closed_box.xpm", &game->img_w, &game->img_h);
}
