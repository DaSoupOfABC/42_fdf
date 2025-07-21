/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 16:59:45 by jenlee            #+#    #+#             */
/*   Updated: 2025/07/21 14:59:14 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "libft.h"
# include "keycodes.h"
# include "../helpers/minilibx-linux/minilibx-linux/mlx.h"
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	colour;
}			t_point;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	x;
	int	y;
}			t_line;

typedef struct s_camera
{
	double	zoom;
	double	z_zoom;
	double	angle;
	int		offset_x;
	int		offset_y;
	double	rotation_x;
	double	rotation_y;
	double	rotation_z;
	double	center_x;
	double	center_y;
}			t_camera;

typedef struct s_map
{
	t_point	**grid;
	int		width;
	int		height;
}				t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_camera	cam;
	t_img		img;
	int			win_w;
	int			win_h;
	int			mouse_down;
	int			drag_type; // 1 = rotate, 2 = pan
	int			prev_x;
	int			prev_y;
	int			move_up;
	int			move_down;
	int			move_left;
	int			move_right;
	int			need_redraw;
}				t_vars;

# define ISO_ANGLE 0.523599

void		free_map(t_map *map);
void		free_split(char **split);
int			count_words_fdf(char *str, char delimiter);
int			count_lines(int fd);
int			ft_atoi_base(const char *str, int base);
void		print_map(t_map *map, int x, int y);
int			open_file(char *file);
t_map		*parse_map(int fd);
t_point		parse_point(char *token, int x, int y);
int			fill_map_row(t_map *map, char *line, int y);
int			init_map(t_map **map, int fd);
int			ft_abs(int n);
void		draw_line(t_vars *mlx, t_point a, t_point b);
void		draw_map(t_vars *mlx, t_map *map);
void		render_map(t_vars *vars, int y);
int			loop_handler(t_vars *vars);
int			key_release(int keycode, t_vars *vars);
int			key_press(int keycode, t_vars *vars);
int			mouse_move(int x, int y, t_vars *vars);
int			mouse_release(int button, int x, int y, t_vars *vars);
int			mouse_press(int button, int x, int y, t_vars *vars);
void		reset_camera(t_vars *vars);
int			mouse_scroll(int button, int x, int y, t_vars *vars);
t_point		apply_camera(t_point p, t_camera *cam, double tmp_x, double tmp_y);
void		clear_image(t_vars *vars);
void		init_image(t_vars *vars);
int			handle_movement_and_zoom(int keycode, t_vars *vars);
double		calculate_initial_zoom(t_map *map, int win_w, int win_h);

#endif
