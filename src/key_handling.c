/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:21:03 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/27 17:21:03 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	handle_movement_and_zoom(int keycode, t_vars *vars)
{
	if (keycode == KEY_LEFT)
		vars->move_left = 1;
	else if (keycode == KEY_RIGHT)
		vars->move_right = 1;
	else if (keycode == KEY_UP)
		vars->move_up = 1;
	else if (keycode == KEY_DOWN)
		vars->move_down = 1;
	else if (keycode == KEY_PLUS || keycode == KEY_KP_PLUS)
		vars->cam.zoom *= 1.1;
	else if (keycode == KEY_MINUS || keycode == KEY_KP_MINUS)
		vars->cam.zoom /= 1.1;
	else if (keycode == KEY_PAGE_UP)
		vars->cam.z_zoom += 0.1;
	else if (keycode == KEY_PAGE_DOWN)
		vars->cam.z_zoom -= 0.1;
	else
		return (0);
	return (1);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == 'r' || keycode == 'R')
		reset_camera(vars);
	else if (keycode == 'q' || keycode == 'Q')
		vars->cam.rotation_x += 0.05;
	else if (keycode == 'w' || keycode == 'W')
		vars->cam.rotation_y += 0.05;
	else if (keycode == 'e' || keycode == 'E')
		vars->cam.rotation_z += 0.05;
	else
		handle_movement_and_zoom(keycode, vars);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 65361)
		vars->move_left = 0;
	else if (keycode == 65363)
		vars->move_right = 0;
	else if (keycode == 65362)
		vars->move_up = 0;
	else if (keycode == 65364)
		vars->move_down = 0;
	return (0);
}

int	loop_handler(t_vars *vars)
{
	if (vars->move_up)
		vars->cam.offset_y -= 3;
	if (vars->move_down)
		vars->cam.offset_y += 3;
	if (vars->move_left)
		vars->cam.offset_x -= 3;
	if (vars->move_right)
		vars->cam.offset_x += 3;
	mlx_clear_window(vars->mlx, vars->window);
	render_map(vars, 0);
	return (0);
}

void	reset_camera(t_vars *vars)
{
	vars->cam.zoom = calculate_initial_zoom(vars->map, vars->win_w, vars->win_h);
	vars->cam.z_zoom = 1;
	vars->cam.angle = ISO_ANGLE;
	vars->cam.offset_x = vars->win_w / 2;
	vars->cam.offset_y = vars->win_h / 2;
	vars->cam.rotation_x = 0;
	vars->cam.rotation_y = 0;
	vars->cam.rotation_z = 0;
	vars->cam.center_x = vars->map->width/2.0;
	vars->cam.center_y = vars->map->height/2.0;
}
