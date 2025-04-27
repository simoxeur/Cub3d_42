/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:52:30 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 15:52:35 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	h_element_hitt(t_data *data, int i)
{
	if (data->map[(int)data->ray_utils->y_tocheck]
		[(int)data->ray_utils->x_tocheck] == '1')
	{
		data->ray_utils->hitt = 1;
		data->ray[i]->h_element_hitt = '1';
		return (1);
	}
	if (data->map[(int)data->ray_utils->y_tocheck]
		[(int)data->ray_utils->x_tocheck] == 'D')
	{
		data->ray_utils->hitt = 1;
		data->ray[i]->h_element_hitt = 'D';
		return (2);
	}
	return (0);
}

int	v_element_hitt(t_data *data, int i)
{
	if (data->map[(int)data->ray_utils->y_tocheck]
		[(int)data->ray_utils->x_tocheck] == '1')
	{
		data->ray_utils->hitt = 1;
		data->ray[i]->v_element_hitt = '1';
		return (1);
	}
	if (data->map[(int)data->ray_utils->y_tocheck]
		[(int)data->ray_utils->x_tocheck] == 'D')
	{
		data->ray_utils->hitt = 1;
		data->ray[i]->v_element_hitt = 'D';
		return (2);
	}
	return (0);
}

void	h_wall_hitt(t_data *data, int i)
{
	while (data->ray_utils->y >= 0 && data->ray_utils->y < data->h * TILE_SIZE
		&& data->ray_utils->x >= 0 && data->ray_utils->x < data->w * TILE_SIZE)
	{
		data->ray_utils->x_tocheck = data->ray_utils->x / TILE_SIZE;
		data->ray_utils->y_tocheck = data->ray_utils->y / TILE_SIZE;
		if (data->ray[i]->is_facing_up && data->ray_utils->y_tocheck > 0)
			data->ray_utils->y_tocheck -= 1;
		if (h_element_hitt(data, i) == 1)
			break ;
		else if (h_element_hitt(data, i) == 2)
		{
			if (abs((int)data->ray_utils->x_tocheck
					- ((int)data->player->x / TILE_SIZE)) < 2
				&& abs((int)data->ray_utils->y_tocheck
					- ((int)data->player->y / TILE_SIZE)) < 2)
				data->ray_utils->open_door = 1;
			else
				break ;
		}
		data->ray_utils->x += data->ray_utils->xstep;
		data->ray_utils->y += data->ray_utils->ystep;
	}
}

void	v_wall_hitt(t_data *data, int i)
{
	while (data->ray_utils->y >= 0 && data->ray_utils->y < data->h * TILE_SIZE
		&& data->ray_utils->x >= 0 && data->ray_utils->x < data->w * TILE_SIZE)
	{
		data->ray_utils->y_tocheck = data->ray_utils->y / TILE_SIZE;
		data->ray_utils->x_tocheck = data->ray_utils->x / TILE_SIZE;
		if (data->ray[i]->is_facing_left && data->ray_utils->x_tocheck > 0)
			data->ray_utils->x_tocheck -= 1;
		if (v_element_hitt(data, i) == 1)
			break ;
		else if (v_element_hitt(data, i) == 2)
		{
			if (abs((int)data->ray_utils->x_tocheck
					- ((int)data->player->x / TILE_SIZE)) < 2
				&& abs((int)data->ray_utils->y_tocheck
					- ((int)data->player->y / TILE_SIZE)) < 2)
				data->ray_utils->open_door = 1;
			else
				break ;
		}
		data->ray_utils->x += data->ray_utils->xstep;
		data->ray_utils->y += data->ray_utils->ystep;
	}
}
