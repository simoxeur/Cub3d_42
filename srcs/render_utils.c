/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:32:38 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/23 16:24:39 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	wall_direction(t_data *data, int r_i)
{
	int	direction;

	direction = 0;
	if (data->ray[r_i]->horizontal_hitt && data->ray[r_i]->is_facing_up)
		direction = 0;
	if (data->ray[r_i]->horizontal_hitt && data->ray[r_i]->is_facing_down)
		direction = 1;
	if (data->ray[r_i]->vertical_hitt && data->ray[r_i]->is_facing_right)
		direction = 2;
	if (data->ray[r_i]->vertical_hitt && data->ray[r_i]->is_facing_left)
		direction = 3;
	return (direction);
}

double	scale_offset(t_data *data, double offset, int direction, char c)
{
	double	scale;

	scale = 1;
	if (c == 'x')
	{
		scale = data->wall_texture[direction]->width / TILE_SIZE;
		offset *= scale;
		return (fmin(fmax(0, offset),
				data->wall_texture[direction]->width - 1));
	}
	if (c == 'y')
	{
		scale = data->wall_texture[direction]->height / TILE_SIZE;
		offset *= scale;
		return (fmin(fmax(0, offset),
				data->wall_texture[direction]->height - 1));
	}
	return (-1);
}

int	find_offset_x(t_data *data, int r_i)
{
	int	offset_x;

	offset_x = 0;
	if (data->ray[r_i]->horizontal_hitt)
		offset_x = (int)data->ray[r_i]->wall_hitt_x % TILE_SIZE;
	if (data->ray[r_i]->vertical_hitt)
		offset_x = (int)data->ray[r_i]->wall_hitt_y % TILE_SIZE;
	return (offset_x);
}
