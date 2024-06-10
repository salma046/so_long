/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:13:06 by salaoui           #+#    #+#             */
/*   Updated: 2024/04/26 20:19:08 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_game
{
	int		heightmap;
	int		x;
	int		y;
	int		count_collect;
	int		move_counter;
	int		row;
	int		colum;
	char	**map;
	char	**map_copy;
	void	*mlx;
	void	*mlx_win;
	void	*player;
	void	*wall;
	void	*bg;
	void	*collect;
	void	*e;
}	t_game;

char		**start_reading_map(int height, char *argv);
int			map_height(int argc, char *argv);
int			map_width(char *argv);
int			move_player(int key_press, t_game *game);
int			is_map_valid(char **map, int h, int w);
int			handle_close_button(t_game *game);
int			move_it(t_game *game, int width, int height);
void		xpm_to_images(void *mlx, t_game *game);
void		put_images_in_window(void *mlx, void *mlx_window, t_game *game);
void		error(char *msg);
void		player_can_win(t_game *game);
void		flood_fill(t_game *game, int move_x, int move_y);
#endif
