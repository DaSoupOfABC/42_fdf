/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:30:17 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/27 15:30:17 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/fdf.h"

void	init_line(t_line *line, t_point a, t_point b)
{
	line->dx = b.x - a.x;
	if (line->dx < 0)
		line->dx = -line->dx;
	line->dy = b.y - a.y;
	if (line->dy < 0)
		line->dy = -line->dy;
	if (a.x < b.x)
		line->sx = 1;
	else
		line->sx = -1;
	if (a.y < b.y)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx - line->dy;
	line->x = a.x;
	line->y = a.y;
}

void	update_error_and_step(t_line *line)
{
	int	err2;

	err2 = 2 * line->err;
	if (err2 > -line->dy)
	{
		line->err -= line->dy;
		line->x += line->sx;
	}
	if (err2 < line->dx)
	{
		line->err += line->dx;
		line->y += line->sy;
	}
}

void	put_pixel(int x, int y, int color, t_vars *vars)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= vars->win_w || y >= vars->win_h)
		return ;
	dst = vars->img.addr + (y * vars->img.line_len + x * (vars->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_vars *vars, t_point a, t_point b)
{
	t_line	line;

	init_line(&line, a, b);
	while (1)
	{
		put_pixel(line.x, line.y, a.colour, vars);
		if (line.x == b.x && line.y == b.y)
			break ;
		update_error_and_step(&line);
	}
}

/*void	render_map(t_vars *vars, int y)
{
	int		x;
	t_point	a;
	t_point	b;

	clear_image(vars);
	while (y < vars->map->height)
	{
		x = -1;
		while (++x < vars->map->width)
		{
			a = apply_camera(vars->map->grid[y][x], &vars->cam, 0, 0);
			if (x < vars->map->width - 1)
			{
				b = apply_camera(vars->map->grid[y][x + 1], &vars->cam, 0, 0);
				draw_line(vars, a, b);
			}
			if (y < vars->map->height - 1)
			{
				b = apply_camera(vars->map->grid[y + 1][x], &vars->cam, 0, 0);
				draw_line(vars, a, b);
			}
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img.img, 0, 0);
	
} COMMENTED OUT FOR DEBUGGING*/

void	render_map(t_vars *vars, int y)
{
	int		x;
	t_point	a;
	t_point	b;

	clear_image(vars);
	while (y < vars->map->height)
	{
		x = -1;
		while (++x < vars->map->width)
		{
			a = apply_camera(vars->map->grid[y][x], &vars->cam, 0, 0);
			if (x < vars->map->width - 1)
			{
				b = apply_camera(vars->map->grid[y][x + 1], &vars->cam, 0, 0);
				draw_line(vars, a, b);
				printf("LINE (R): A(%d,%d,%d) -> B(%d,%d,%d)\n",
					vars->map->grid[y][x].x, vars->map->grid[y][x].y, vars->map->grid[y][x].z,
					vars->map->grid[y][x + 1].x, vars->map->grid[y][x + 1].y, vars->map->grid[y][x + 1].z);
			}
			if (y < vars->map->height - 1)
			{
				b = apply_camera(vars->map->grid[y + 1][x], &vars->cam, 0, 0);
				draw_line(vars, a, b);
				printf("LINE (D): A(%d,%d,%d) -> B(%d,%d,%d)\n",
					vars->map->grid[y][x].x, vars->map->grid[y][x].y, vars->map->grid[y][x].z,
					vars->map->grid[y + 1][x].x, vars->map->grid[y + 1][x].y, vars->map->grid[y + 1][x].z);
			}
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->window, vars->img.img, 0, 0);
}

