/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:07:00 by salaoui           #+#    #+#             */
/*   Updated: 2024/04/22 14:09:19 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_print/ft_printf.h"

int	up_handle(int key_press, t_game *game)
{
	int	i;
	int	j;
	int	t;

	i = game->x;
	j = game->y;
	if (key_press == 13)
	{
		i--;
		if (game->map[i][j] == '1')
			return (0);
		t = move_it(game, i, j);
		if (t == 0)
			return (0);
		else if (t != 0)
		{
			game->move_counter++;
			ft_printf("Move number: %i\n", game->move_counter);
			game->map[i + 1][j] = '0';
		}
	}
	return (1);
}

int	down_handle(int key_press, t_game *game)
{
	int	i;
	int	j;
	int	t;

	i = game->x;
	j = game->y;
	if (key_press == 1)
	{
		i++;
		if (game->map[i][j] == '1')
			return (0);
		t = move_it(game, i, j);
		if (t == 0)
			return (0);
		else if (t != 0)
		{
			game->move_counter++;
			ft_printf("Move number: %i\n", game->move_counter);
			game->map[i - 1][j] = '0';
		}
		if (t == 5)
			game->map[i - 1][j] = '0';
	}
	return (1);
}

int	right_handle(int key_press, t_game *game)
{
	int	i;
	int	j;
	int	t;

	i = game->x;
	j = game->y;
	if (key_press == 2)
	{
		j++;
		if (game->map[i][j] == '1')
			return (0);
		t = move_it(game, i, j);
		if (t == 0)
			return (0);
		else if (t != 0)
		{
			game->move_counter++;
			ft_printf("Move number: %i\n", game->move_counter);
			game->map[i][j - 1] = '0';
		}
	}
	return (1);
}

int	left_handle(int key_press, t_game *game)
{
	int	i;
	int	j;
	int	t;

	i = game->x;
	j = game->y;
	if (key_press == 0)
	{
		j--;
		if (game->map[i][j] == '1')
			return (0);
		t = move_it(game, i, j);
		if (t == 0)
			return (0);
		else if (t != 0)
		{
			game->move_counter++;
			ft_printf("Move number: %i\n", game->move_counter);
			game->map[i][j + 1] = '0';
		}
	}
	return (1);
}

int	move_player(int key_press, t_game *game)
{
	int	i;

	i = 0;
	if (key_press == 13)
		i = up_handle(key_press, game);
	if (key_press == 1)
		i = down_handle(key_press, game);
	if (key_press == 2)
		i = right_handle(key_press, game);
	if (key_press == 0)
		i = left_handle(key_press, game);
	if (key_press == 53)
		handle_close_button(game);
	if (i != 0)
		put_images_in_window(game->mlx, game->mlx_win, game);
	return (1);
}
