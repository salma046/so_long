/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:17:04 by salaoui           #+#    #+#             */
/*   Updated: 2024/04/26 20:20:20 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	put_player(t_game *game, int w, int h)
{
	w = w * 40;
	h = h * 40;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, w, h);
	game->x = h / 40;
	game->y = w / 40;
}

void	put_collect(t_game *game, int w, int h)
{
	w = w * 40;
	h = h * 40;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->collect, w, h);
	game->count_collect++;
}

void	xpm_to_images(void *mlx, t_game *game)
{
	int	pw;
	int	ph;

	game->player = mlx_xpm_file_to_image(mlx, "img/img_player.xpm", &pw, &ph);
	game->wall = mlx_xpm_file_to_image(mlx, "img/img_wall.xpm", &pw, &ph);
	game->bg = mlx_xpm_file_to_image(mlx, "img/img_bg.xpm", &pw, &ph);
	game->collect = mlx_xpm_file_to_image(mlx, "img/img_collect.xpm", &pw, &ph);
	game->e = mlx_xpm_file_to_image(mlx, "img/img_exit.xpm", &pw, &ph);
	if (game->player == NULL || game->wall == NULL)
		error("image not found!");
	if (game->bg == NULL || game->collect == NULL || game->e == NULL)
		error("image not found!");
}

void	put_images_in_window(void *mlx, void *win, t_game *game)
{
	int	w;
	int	h;

	game->count_collect = 0;
	h = 0;
	while (game->map[h] != NULL)
	{
		w = 0;
		while (game->map[h][w] != '\n' && game->map[h][w] != '\0')
		{
			if (game->map[h][w] == '1')
				mlx_put_image_to_window(mlx, win, game->wall, w * 40, h * 40);
			if (game->map[h][w] == '0')
				mlx_put_image_to_window(mlx, win, game->bg, w * 40, h * 40);
			if (game->map[h][w] == 'E')
				mlx_put_image_to_window(mlx, win, game->e, w * 40, h * 40);
			if (game->map[h][w] == 'C')
				put_collect(game, w, h);
			if (game->map[h][w] == 'P')
				put_player(game, w, h);
			w++;
		}
		h++;
	}
}

int	main(int argc, char	*argv[])
{
	t_game	*game;
	int		h;
	int		w;
	int		map_valid;

	game = (t_game *)malloc(sizeof(t_game));
	game->move_counter = 0;
	game->mlx = mlx_init ();
	if (game == NULL || game->mlx == (void *)0)
		error ("Memory allocation failed!");
	game->row = map_height(argc, argv[1]);
	h = game->row;
	game->map = start_reading_map(h, argv[1]);
	game->map_copy = start_reading_map(h, argv[1]);
	game->colum = map_width(argv[1]);
	w = game->colum;
	map_valid = is_map_valid(game->map, h, w);
	player_can_win(game);
	game->mlx_win = mlx_new_window(game->mlx, w * 40, h * 40, "./so_long");
	xpm_to_images(game->mlx, game);
	put_images_in_window(game->mlx, game->mlx_win, game);
	mlx_key_hook(game->mlx_win, move_player, game);
	mlx_hook(game->mlx_win, 17, 0, handle_close_button, game);
	mlx_loop(game->mlx);
	return (1);
}
