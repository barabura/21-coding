/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:17:06 by baura             #+#    #+#             */
/*   Updated: 2022/07/08 12:49:36 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_img(t_game *game, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->player_img, w * game->img_size, h * game->img_size);
	game->player_x = w;
	game->player_y = h;
}

void	put_exit_img(t_game *game, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->empty_space_img, w * game->img_size, h * game->img_size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, \
	game->exit_img, w * game->img_size, h * game->img_size);
	game->exit_x = w;
	game->exit_y = h;
}

void	put_images(t_game *game, int w, int h)
{
	if (game->map[h][w] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->wall_img, w * game->img_size, h * game->img_size);
	if (game->map[h][w] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->empty_space_img, w * game->img_size, h * game->img_size);
	if (game->map[h][w] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->empty_space_img, w * game->img_size, h * game->img_size);
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->collectable_img, w * game->img_size, h * game->img_size);
	}
	if (game->map[h][w] == 'P')
		put_player_img(game, w, h);
	if (game->map[h][w] == 'E')
		put_exit_img(game, w, h);
}

int	fill_window(t_game *game)
{
	int	w;
	int	h;

	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (game->map[h][++w])
			put_images(game, w, h);
	}
	return (1);
}
