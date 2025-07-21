/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:18:40 by jenlee            #+#    #+#             */
/*   Updated: 2025/07/21 13:36:06 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fdf.h"

int	mouse_handler(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 4)
		vars->cam.zoom *= 1.1;
	else if (button == 5)
		vars->cam.zoom /= 1.1;
	mlx_clear_window(vars->mlx, vars->window);
	render_map(vars, 0);
	return (0);
}

int	expose_handler(t_vars *vars)
{
	int	w;
	int	h;

	mlx_get_screen_size(vars->mlx, &w, &h);
	vars->win_w = 1000;
	vars->win_h = 500;
	render_map(vars, 0);
	return (0);
}

double	calculate_initial_zoom(t_map *map, int win_w, int win_h)
{
	double	margin = 0.8;
	double	zoom_x = (win_w * margin) / map->width;
	double	zoom_y = (win_h * margin) / map->height;

	if (zoom_x < zoom_y)
		return (zoom_x);
	else
		return (zoom_y);
}


int	main(int argc, char *argv[])
{
	t_vars	vars;

	ft_bzero(&vars, sizeof(t_vars));
	if (argc != 2)
		return (ft_putstr("Usage: ./fdf <map>\n"), 1);
	vars.map = parse_map(open_file(argv[1]));
	if (!vars.map)
		return (ft_putstr("Error parsing map or map file not found\n"), 1);
	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &vars.win_w, &vars.win_h);
	vars.window = mlx_new_window(vars.mlx, vars.win_w, vars.win_h, "FdF");
	reset_camera(&vars);
	init_image(&vars);
	render_map(&vars, 0);
	mlx_key_hook(vars.window, loop_handler, &vars);
	mlx_hook(vars.window, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.window, 3, 1L << 1, key_release, &vars);
	mlx_mouse_hook(vars.window, mouse_handler, &vars);
	mlx_hook(vars.window, 4, 1L << 2, mouse_press, &vars);
	mlx_hook(vars.window, 5, 1L << 3, mouse_release, &vars);
	mlx_hook(vars.window, 6, 1L << 6, mouse_move, &vars);
	mlx_loop_hook(vars.mlx, loop_handler, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
