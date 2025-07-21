/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:36:36 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/23 16:59:27 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/fdf.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map -> height)
	{
		free(map -> grid[i]);
		i++;
	}
	free(map -> grid);
	free(map);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	print_spaces(int value)
{
	if (value < 10)
		ft_putstr("  ");
	else if (value < 100)
		ft_putstr(" ");
}

void	print_map(t_map *map, int x, int y)
{
	if (!map || !map->grid)
		return ;
	y = 0;
	while (y < map->height)
	{
		if (!map->grid[y])
		{
			ft_putstr("NULL row\n");
			y++;
			continue ;
		}
		x = 0;
		while (x < map->width)
		{
			print_spaces(map->grid[y][x].z);
			ft_putnbr_fd(map->grid[y][x].z, 1);
			if (x < map->width - 1)
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
