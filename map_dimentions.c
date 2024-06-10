/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimentions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salaoui <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:26:58 by salaoui           #+#    #+#             */
/*   Updated: 2024/04/19 10:30:15 by salaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	ber_extention(int argc, char *arg)
{
	int	i;

	if (argc != 2)
		error ("Arguments not valid!");
	i = ft_strlen(arg);
	if (arg[i - 4] != '.' || arg[i - 3] != 'b')
		error("invalid file extention!");
	if (arg[i - 2] != 'e' || arg[i - 1] != 'r')
		error("invalid file extention!");
}

int	map_height(int argc, char *argv)
{
	char	*line;
	int		heightmap;
	int		fd;

	ber_extention(argc, argv);
	heightmap = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (0);
	}
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		heightmap++;
		free(line);
	}
	close(fd);
	return (heightmap);
}

char	*read_map(char *string)
{
	int		j;
	char	*map;

	j = 0;
	while (string[j] != '\0')
		j++;
	map = (char *)malloc(sizeof(char) * (j + 1));
	if (map == '\0')
		return (0);
	j = 0;
	while (string[j] != '\0')
	{
		map[j] = string[j];
		j++;
	}
	map[j] = '\0';
	return (map);
}

char	**start_reading_map(int height, char *argv)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (map == NULL)
		return (0);
	map[height] = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[i] = read_map(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
		free(line);
	close(fd);
	return (map);
}

int	map_width(char *argv)
{
	int		fd;
	char	*line;
	int		width;

	width = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line[width] != '\n')
		width++;
	close(fd);
	free(line);
	return (width);
}
