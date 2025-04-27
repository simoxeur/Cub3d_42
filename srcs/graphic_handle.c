/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_handle_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:45:14 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 15:49:47 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	render(t_data *data)
{
	ray_init(data);
	ray_handler(data);
	render3d(data);
	render_minimap(data);
	return (0);
}

void	move_player(t_data *data, int direction)
{
	if (direction == 1)
		if (no_wall(data, new_pos_x(data, 1), new_pos_y(data, 1)))
			new_position(data, direction);
	if (direction == 2)
		if (no_wall(data, new_pos_x(data, 2), new_pos_y(data, 2)))
			new_position(data, direction);
	if (direction == 3)
		if (no_wall(data, new_pos_x(data, 3), new_pos_y(data, 3)))
			new_position(data, direction);
	if (direction == 4)
		if (no_wall(data, new_pos_x(data, 4), new_pos_y(data, 4)))
			new_position(data, direction);
	if (direction == 5 || direction == 6)
		new_position(data, direction);
	render(data);
}

void	moving(t_data *data)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(data->window->mlx, &x, &y);
	if (x > WIDTH / 2 && data->mouse_move % 2 != 0)
		move_player(data, 5);
	if (x < WIDTH / 2 && data->mouse_move % 2 != 0)
		move_player(data, 6);
	if (mlx_is_key_down(data->window->mlx, MLX_KEY_W))
		move_player(data, 1);
	if (mlx_is_key_down(data->window->mlx, MLX_KEY_S))
		move_player(data, 2);
	if (mlx_is_key_down(data->window->mlx, MLX_KEY_D))
		move_player(data, 3);
	if (mlx_is_key_down(data->window->mlx, MLX_KEY_A))
		move_player(data, 4);
	if (mlx_is_key_down(data->window->mlx, MLX_KEY_RIGHT))
		move_player(data, 5);
	if (mlx_is_key_down(data->window->mlx, MLX_KEY_LEFT))
		move_player(data, 6);
}

void	loop_func(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	moving(data);
	render_torch(data);
	mlx_set_mouse_pos(data->window->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor_mode(data->window->mlx, MLX_MOUSE_HIDDEN);
}

int	graphic_handle(t_data *data)
{
	if (init_values(data))
		return (1);
	data->door_texture = mlx_load_png(DOOR_PATH);
	if (!data->door_texture)
		return (error_mlx(data), 1);
	data->window->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!data->window->mlx)
		return (error_mlx(data), 1);
	data->window->img = mlx_new_image(data->window->mlx, WIDTH, HEIGHT);
	data->window->inimate_img = mlx_new_image(data->window->mlx, WIDTH, HEIGHT);
	if (!data->window->img || mlx_image_to_window(data->window->mlx,
			data->window->img, 0, 0) < 0)
		return (error_mlx(data), 1);
	load_torch_frames(data);
	mlx_key_hook(data->window->mlx, &key_hook, data);
	mlx_loop_hook(data->window->mlx, &loop_func, data);
	if (render(data))
		return (1);
	mlx_loop(data->window->mlx);
	return (0);
}
