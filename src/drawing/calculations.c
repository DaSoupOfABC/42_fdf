/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:26:33 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/27 15:26:33 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/fdf.h"

double	get_auto_z_zoom(t_map *map)
{
	if (map->width > 100 || map->height > 100)
		return (3.0);
	else if (map->width > 50)
		return (10.0);
	else
		return (15.0);
}

t_point	apply_camera(t_point p, t_camera *cam, double tmp_x, double tmp_y)
{
	t_point	proj;
	double	tmp_z;

	p.x -= cam ->center_x;
	p.y -= cam ->center_y;
	p.x *= cam->zoom;
	p.y *= cam->zoom;
	p.z *= cam->zoom * cam->z_zoom * 0.2;
	tmp_x = p.x * cos(cam->rotation_z) - p.y * sin(cam->rotation_z);
	tmp_y = p.x * sin(cam->rotation_z) + p.y * cos(cam->rotation_z);
	p.x = tmp_x;
	p.y = tmp_y;
	tmp_y = p.y * cos(cam->rotation_x) - p.z * sin(cam->rotation_x);
	tmp_z = p.y * sin(cam->rotation_x) + p.z * cos(cam->rotation_x);
	p.y = tmp_y;
	p.z = tmp_z;
	tmp_x = p.x * cos(cam->rotation_y) + p.z * sin(cam->rotation_y);
	tmp_z = -p.x * sin(cam->rotation_y) + p.z * cos(cam->rotation_y);
	p.x = tmp_x;
	p.z = tmp_z;
	proj.x = (int)((p.x - p.y) * cos(cam->angle));
	proj.y = (int)((p.x + p.y) * sin(cam->angle) - p.z);
	proj.x += cam->offset_x;
	proj.y += cam->offset_y;
	proj.colour = p.colour;
	return (proj);
}

void	clear_image(t_vars *vars)
{
	ft_bzero(vars->img.addr, vars->win_w * vars->win_h * 4);
}

void	init_image(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, vars->win_w, vars->win_h);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp,
			&vars->img.line_len, &vars->img.endian);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
