/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:41:02 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 13:25:53 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ray_utils_init(t_data *data)
{
	data->ray_utils->x = 0;
	data->ray_utils->y = 0;
	data->ray_utils->xstep = 0;
	data->ray_utils->ystep = 0;
	data->ray_utils->x_tocheck = 0;
	data->ray_utils->y_tocheck = 0;
	data->ray_utils->hitt = 0;
}

static double	horizontal_intersection(t_data *data, int i)
{
	ray_utils_init(data);
	data->ray_utils->y = floor(data->player->y / TILE_SIZE) * TILE_SIZE;
	if (data->ray[i]->is_facing_down)
		data->ray_utils->y += TILE_SIZE;
	data->ray_utils->x = data->player->x + (data->ray_utils->y
			- data->player->y) / tan(data->ray[i]->ray_angle);
	data->ray_utils->ystep = TILE_SIZE;
	if (data->ray[i]->is_facing_up)
		data->ray_utils->ystep *= -1;
	data->ray_utils->xstep = TILE_SIZE / tan(data->ray[i]->ray_angle);
	if ((data->ray[i]->is_facing_left && data->ray_utils->xstep > 0)
		|| (data->ray[i]->is_facing_right && data->ray_utils->xstep < 0))
		data->ray_utils->xstep *= -1;
	h_wall_hitt(data, i);
	data->ray[i]->h_hittx = (data->ray_utils->x_tocheck * TILE_SIZE);
	data->ray[i]->h_hitty = (data->ray_utils->y_tocheck * TILE_SIZE);
	if (data->ray[i]->is_facing_up)
		data->ray[i]->h_hitty += TILE_SIZE;
	if (!data->ray_utils->hitt)
		return (-1);
	return (sqrt(pow(data->player->x - data->ray_utils->x, 2)
			+ pow(data->player->y - data->ray_utils->y, 2)));
}

static double	vertical_intersection(t_data *data, int i)
{
	ray_utils_init(data);
	data->ray_utils->x = floor(data->player->x / TILE_SIZE) * TILE_SIZE;
	if (data->ray[i]->is_facing_right)
		data->ray_utils->x += TILE_SIZE;
	data->ray_utils->y = data->player->y + (data->ray_utils->x
			- data->player->x) * tan(data->ray[i]->ray_angle);
	data->ray_utils->xstep = TILE_SIZE;
	if (data->ray[i]->is_facing_left)
		data->ray_utils->xstep *= -1;
	data->ray_utils->ystep = TILE_SIZE * tan(data->ray[i]->ray_angle);
	if ((data->ray[i]->is_facing_up && data->ray_utils->ystep > 0)
		|| (data->ray[i]->is_facing_down && data->ray_utils->ystep < 0))
		data->ray_utils->ystep *= -1;
	v_wall_hitt(data, i);
	data->ray[i]->v_hittx = data->ray_utils->x_tocheck * TILE_SIZE;
	if (data->ray[i]->is_facing_left)
		data->ray[i]->v_hittx += TILE_SIZE;
	data->ray[i]->v_hitty = (data->ray_utils->y_tocheck) * TILE_SIZE;
	if (!data->ray_utils->hitt)
		return (-1);
	return (sqrt(pow(data->player->x - data->ray_utils->x, 2)
			+ pow(data->player->y - data->ray_utils->y, 2)));
}

void	ray_cast(t_data *data, double ray_angle, int i)
{
	double	h_dst;
	double	v_dst;

	h_dst = 0;
	v_dst = 0;
	ray_angle = fix_angle(ray_angle);
	data->ray[i]->ray_angle = ray_angle;
	if (ray_angle >= 0 && ray_angle <= M_PI)
		data->ray[i]->is_facing_down = 1;
	else
		data->ray[i]->is_facing_up = 1;
	if ((ray_angle >= 0 && ray_angle <= M_PI / 2)
		|| (ray_angle >= 3 * M_PI / 2 && ray_angle <= 2 * M_PI))
		data->ray[i]->is_facing_right = 1;
	else
		data->ray[i]->is_facing_left = 1;
	h_dst = horizontal_intersection(data, i);
	v_dst = vertical_intersection(data, i);
	dst_cmp(data, h_dst, v_dst, i);
}

void	ray_handler(t_data *data)
{
	double	ray_angle;
	t_ray	rays;
	int		i;

	i = 0;
	ray_angle = data->player->angle - ((FOV / 2) * (M_PI / 180.0));
	while (i < N_RAYS)
	{
		ray_cast(data, ray_angle, i);
		rays[i].ray_angle = ray_angle;
		ray_angle += (((double)FOV / (double)N_RAYS) * (M_PI / 180.0));
		i++;
	}
}
