/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:33:41 by salaoui           #+#    #+#             */
/*   Updated: 2024/04/27 13:31:47 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_print/ft_printf.h"

int	handle_close_button(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int	if_no_collect(t_game *game)
{
	game->move_counter++;
	ft_printf("\nCONGRATS YOU WON with %i moves!!\n", game->move_counter);
	return (handle_close_button(game));
}

int	move_it(t_game *game, int width, int height)
{
	if (game->map[width][height] == 'E')
	{
		if (game->count_collect != 0)
			return (0);
		else
			return (if_no_collect(game));
	}
	if (game->map[width][height] == '0')
	{
		game->map[width][height] = 'P';
		game->x = width;
		game->y = height;
		return (1);
	}
	if (game->map[width][height] == 'C')
	{
		game->map[width][height] = 'P';
		game->x = width;
		game->y = height;
		game->count_collect--;
		return (1);
	}
	return (0);
}
