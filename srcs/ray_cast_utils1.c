/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:33:26 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 15:52:26 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	fix_angle(double angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	dst_cmp(t_data *data, double h_dst, double v_dst, int i)
{
	if ((h_dst > 0 && h_dst < v_dst) || v_dst < 0)
	{
		data->ray[i]->ray_dst = h_dst;
		if (h_dst >= 0)
		{
			data->ray[i]->wall_hitt_x = data->ray[i]->h_hittx;
			data->ray[i]->wall_hitt_y = data->ray[i]->h_hitty;
			data->ray[i]->horizontal_hitt = 1;
			data->ray[i]->element_hitt = data->ray[i]->h_element_hitt;
		}
	}
	else
	{
		data->ray[i]->ray_dst = v_dst;
		if (v_dst >= 0)
		{
			data->ray[i]->wall_hitt_x = data->ray[i]->v_hittx;
			data->ray[i]->wall_hitt_y = data->ray[i]->v_hitty;
			data->ray[i]->vertical_hitt = 1;
			data->ray[i]->element_hitt = data->ray[i]->v_element_hitt;
		}
	}
}

void	ray_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < N_RAYS)
	{
		data->ray[i]->is_facing_up = 0;
		data->ray[i]->is_facing_down = 0;
		data->ray[i]->is_facing_right = 0;
		data->ray[i]->is_facing_left = 0;
		data->ray[i]->ray_angle = 0;
		data->ray[i]->ray_dst = 0;
		data->ray[i]->h_hittx = 0;
		data->ray[i]->h_hitty = 0;
		data->ray[i]->v_hittx = 0;
		data->ray[i]->v_hitty = 0;
		data->ray[i]->horizontal_hitt = 0;
		data->ray[i]->vertical_hitt = 0;
		data->ray[i]->wall_hitt_x = -1;
		data->ray[i]->wall_hitt_y = -1;
		data->ray_utils->open_door = 0;
		i++;
	}
}
