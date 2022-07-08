/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:31:41 by baura             #+#    #+#             */
/*   Updated: 2022/07/08 19:37:16 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(char *str)
{
	ft_putstr_fd("Error: ", 1);
	ft_putstr_fd(str, 1);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	check_argument(int argc, char *arg)
{
	int	len;

	if (argc < 2)
		error_message("You must use a map to start the game");
	if (argc > 2)
		error_message("You can use only 1 map at a time");
	if (argc == 2)
	{
		len = ft_strlen(arg); 
		if ((arg[len - 1] != 'r') && (arg[len - 2] != 'e') && \
			(arg[len - 3] != 'b') && (arg[len - 1] != '.'))
			error_message("Your map must have .ber file extension");
	}
}

int	close_game(t_game *game)
{
	(void) game;
	ft_putstr_fd("Exit\n", 1);
	exit (EXIT_SUCCESS);
}

void	print_steps(t_game *game)
{
	char	*s;

	s = ft_itoa(game->steps);
	ft_putstr_fd("STEPS: ", 1);
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
	free(s);
}

void	make_window(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width * game->img_size, \
					game->height * game->img_size, "so_long");
}
