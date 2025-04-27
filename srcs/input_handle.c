/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:35:32 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/23 14:21:14 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	no_wall(t_data *data, double x, double y)
{
	double	angle;
	double	x_tocheck;
	double	y_tocheck;
	int		dst;

	angle = 0;
	x_tocheck = 0;
	y_tocheck = 0;
	dst = 5;
	if (x < 0 || y < 0)
		return (0);
	while (angle < 2 * M_PI)
	{
		x_tocheck = x + cos(angle) * dst;
		y_tocheck = y + sin(angle) * dst;
		if (data->map[(int)y_tocheck / TILE_SIZE]
			[(int)x_tocheck / TILE_SIZE] == '1')
			return (0);
		angle += 0.1 * M_PI;
	}
	return (1);
}

void	new_position(t_data *data, int direction)
{
	(direction == 1) && (data->player->x += cos(data->player->angle)
		* data->player->step_size) && (data->player->y
			+= sin(data->player->angle) * data->player->step_size);
	(direction == 2) && (data->player->x -= cos(data->player->angle)
		* data->player->step_size) && (data->player->y -=
			sin(data->player->angle) * data->player->step_size);
	(direction == 3) && (data->player->x += cos(data->player->angle + M_PI_2)
		* data->player->step_size) && (data->player->y +=
			sin(data->player->angle + M_PI_2) * data->player->step_size);
	(direction == 4) && ((data->player->x += cos(data->player->angle - M_PI_2)
		* data->player->step_size) && (data->player->y +=
			sin(data->player->angle - M_PI_2) * data->player->step_size));
	(direction == 5)
		&& (data->player->angle += M_PI * data->player->turn_speed);
	(direction == 6)
		&& (data->player->angle -= M_PI * data->player->turn_speed);
}

double	new_pos_y(t_data *data, int direction)
{
	if (direction == 1)
		return (data->player->y + sin(data->player->angle)
			* data->player->step_size);
	if (direction == 2)
		return (data->player->y - sin(data->player->angle)
			* data->player->step_size);
	if (direction == 3)
		return (data->player->y + sin(data->player->angle + M_PI_2)
			* data->player->step_size);
	if (direction == 4)
		return (data->player->y + sin(data->player->angle - M_PI_2)
			* data->player->step_size);
	return (-1);
}

double	new_pos_x(t_data *data, int direction)
{
	if (direction == 1)
		return (data->player->x + cos(data->player->angle)
			* data->player->step_size);
	if (direction == 2)
		return (data->player->x - cos(data->player->angle)
			* data->player->step_size);
	if (direction == 3)
		return (data->player->x + cos(data->player->angle + M_PI_2)
			* data->player->step_size);
	if (direction == 4)
		return (data->player->x + cos(data->player->angle - M_PI_2)
			* data->player->step_size);
	return (-1);
}
