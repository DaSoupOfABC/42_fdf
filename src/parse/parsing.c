/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:27:20 by jenlee            #+#    #+#             */
/*   Updated: 2025/07/11 18:43:09 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

int	init_map(t_map **map, int fd)
{
	*map = malloc(sizeof(t_map));
	if (!*map)
		return (0);
	(*map)->height = count_lines(fd);
	lseek(fd, 0, SEEK_SET);
	(*map)->grid = malloc(sizeof(t_point *) * (*map)->height);
	if (!(*map)->grid)
		return (0);
	return (1);
}

int	validate_map_width(int *expected, int current)
{
	if (*expected == -1)
	{
		*expected = current;
		return (1);
	}
	if (current != *expected)
	{
		ft_putstr("Error: inconsistent map width\n");
		return (1);
	}
	return (1);
}

int	fill_map_row(t_map *map, char *line, int y)
{
	char	**tokens;
	int		x;

	map->grid[y] = malloc(sizeof(t_point) * map->width);
	if (!map->grid[y])
		return (0);
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (0);
	x = 0;
	while (x < map->width)
	{
		map->grid[y][x] = parse_point(tokens[x], x, y);
		x++;
	}
	free_split(tokens);
	return (1);
}

t_point	parse_point(char *token, int x, int y)
{
	t_point	p;
	char	**split;

	split = ft_split(token, ',');
	p.x = x;
	p.y = y;
	p.z = ft_atoi(split[0]);
	if (split[1])
		p.colour = ft_atoi_base(split[1], 16);
	else
		p.colour = 0xFFFFFF;
	free_split(split);
	return (p);
}

t_map	*parse_map(int fd)
{
	t_map	*map;
	char	*line;
	int		y;
	int		expected_width;
	int		current_width;

	if (!init_map(&map, fd) || fd < 0)
		return (NULL);
	expected_width = -1;
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		current_width = count_words_fdf(line, ' ');
		if (!validate_map_width(&expected_width, current_width))
			return (NULL);
		map->width = expected_width;
		if (!fill_map_row(map, line, y))
			return (NULL);
		free(line);
		y++;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
