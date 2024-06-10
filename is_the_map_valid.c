/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_the_map_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:31:56 by salaoui           #+#    #+#             */
/*   Updated: 2024/04/22 11:53:54 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_game_object(char **map, int h, int j, int i)
{
	int	p;
	int	e;
	int	collects;

	p = 0;
	e = 0;
	collects = 0;
	while (i < h)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				collects++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || collects == 0)
		return (0);
	return (1);
}

int	ones_in_edges(char **map, int h, int w)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (i == 0 || i == h - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			if (j == 0 || j == w - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(char **map, int w, int i)
{
	char	c;
	int		j;

	j = 0;
	if (map[i][j] == '\n')
		return (0);
	while (map[i][j] != '\n' && map[i][j] != '\0')
	{
		c = map[i][j];
		if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
			return (0);
		if (j == w)
			return (0);
		j++;
	}
	if (map[i][j] == '\n')
	{
		if (j != w)
			return (0);
	}
	return (1);
}

int	is_map_valid(char **map, int h, int w)
{
	int		i;
	int		j;
	int		l;
	int		b;

	i = 0;
	j = 0;
	if (map == 0 || h == 0 || w == 0)
		error ("Try a valid map!");
	while (i < h)
	{
		if (check_map(map, w, i) == 0)
			error ("Try a valid map!");
		i++;
	}
	if (map[h - 1][w] == '\n')
		error ("Try a valid map!");
	i = 0;
	l = count_game_object(map, h, j, i);
	b = ones_in_edges(map, h, w);
	if (l == 0 || b == 0)
		error ("Try a valid map!");
	return (1);
}
