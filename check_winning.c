/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_winning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:41:10 by salaoui           #+#    #+#             */
/*   Updated: 2024/05/01 12:41:14 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_position(t_game *game, int *pl_row, int *pl_colun)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_copy[i])
	{
		j = 0;
		while (game->map_copy[i][j])
		{
			if (game->map_copy[i][j] == 'P')
			{
				*pl_row = i;
				*pl_colun = j;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_game *game, int move_x, int move_y)
{
	if (move_x < 0 || move_y < 0 || move_x >= game->row
		|| move_y >= game->colum || game->map_copy[move_x][move_y] == '1'
			|| game->map_copy[move_x][move_y] == 'X')
		return ;
	if (game->map_copy[move_x][move_y] == 'C')
		game->map_copy[move_x][move_y] = '0';
	else if (game->map_copy[move_x][move_y] == 'E')
	{
		game->map_copy[move_x][move_y] = 'X';
		return ;
	}
	game->map_copy[move_x][move_y] = 'X';
	flood_fill(game, move_x - 1, move_y);
	flood_fill(game, move_x + 1, move_y);
	flood_fill(game, move_x, move_y - 1);
	flood_fill(game, move_x, move_y + 1);
}

void	player_can_win(t_game *game)
{
	int		pl_row;
	int		pl_colun;
	int		can_row;
	int		can_colun;

	pl_row = 0;
	pl_colun = 0;
	can_row = 0;
	ft_player_position(game, &pl_row, &pl_colun);
	flood_fill(game, pl_row, pl_colun);
	while (game->map_copy[can_row])
	{
		can_colun = 0;
		while (game->map_copy[can_row][can_colun])
		{
			if (game->map_copy[can_row][can_colun] == 'C'
				|| game->map_copy[can_row][can_colun] == 'E')
				error("There is no posible way to win");
			can_colun++;
		}
		can_row++;
	}
}
