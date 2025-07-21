/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:19:14 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/27 17:19:14 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/fdf.h"

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
	{
		vars->mouse_down = 1;
		vars->drag_type = 1;
	}
	else if (button == 3)
	{
		vars->mouse_down = 1;
		vars->drag_type = 2;
	}
	else if (button == 4)
		vars->cam.zoom *= 1.1;
	else if (button == 5)
		vars->cam.zoom /= 1.1;
	vars->prev_x = x;
	vars->prev_y = y;
	mlx_clear_window(vars->mlx, vars->window);
	render_map(vars, 0);
	return (0);
}

int	mouse_release(int button, int x, int y, t_vars *vars)
{
	(void)button;
	(void)x;
	(void)y;
	vars->mouse_down = 0;
	vars->drag_type = 0;
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	int	dx;
	int	dy;

	if (!vars->mouse_down)
		return (0);
	dx = x - vars->prev_x;
	dy = y - vars->prev_y;
	if (vars->drag_type == 1)
	{
		vars->cam.rotation_y += dx * 0.01;
		vars->cam.rotation_x += dy * 0.01;
	}
	else if (vars->drag_type == 2)
	{
		vars->cam.offset_x += dx;
		vars->cam.offset_y += dy;
	}
	vars->prev_x = x;
	vars->prev_y = y;
	mlx_clear_window(vars->mlx, vars->window);
	render_map(vars, 0);
	return (0);
}
