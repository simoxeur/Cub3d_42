/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:41:17 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 15:56:15 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	f_c_autolum(t_data *data, char c_f, int f_i)
{
	double	h;

	h = (double)HEIGHT;
	if (c_f == 'c')
	{
		(data->hold_lamp % 2 != 0) && (data->c_lum = 40);
		(data->hold_lamp % 2 == 0) && (data->c_lum = 60);
	}
	if (c_f == 'f')
	{
		(data->hold_lamp % 2 != 0)
			&& (data->f_lum = (f_i / h) * 100);
		(data->hold_lamp % 2 == 0)
			&& (data->f_lum = (f_i / h) * 80);
	}
}

void	draw_f_c(t_data *data, int r_i, double top_pix, double bot_pix)
{
	int		i;

	i = -1;
	if (top_pix < 0 || bot_pix < 0)
		return ;
	while (++i < top_pix)
	{
		f_c_autolum(data, 'c', 0);
		mlx_put_pixel(data->window->img, r_i, i,
			extract_color(data->ceiling_color, data->c_lum));
	}
	i = bot_pix;
	while (i < HEIGHT)
	{
		f_c_autolum(data, 'f', i);
		(data->f_lum >= 100) && (data->f_lum = 100);
		mlx_put_pixel(data->window->img, r_i, i,
			extract_color(data->floor_color, data->f_lum));
		i++;
	}
}

void	draw_walls(t_data *data, int r_i, double top_pix, double bot_pix)
{
	int		d;
	int		color;
	double	y;
	double	offset_x;
	double	offset_y;

	d = wall_direction(data, r_i);
	color = 0;
	y = top_pix;
	offset_x = 0;
	offset_y = 0;
	while (y < bot_pix)
	{
		offset_x = find_offset_x(data, r_i);
		offset_y = (y - data->ray[r_i]->top_wall) * (TILE_SIZE / data->ray[r_i]
				->wall_height);
		offset_x = scale_offset(data, offset_x, d, 'x');
		offset_y = scale_offset(data, offset_y, d, 'y');
		color = texture_pixel_color(data, offset_x, offset_y, d);
		(data->ray[r_i]->vertical_hitt) && (color = darken_color(color, 0.75));
		(data->hold_lamp % 2 != 0)
				&& (color = color | (5 << 24));
		mlx_put_pixel(data->window->img, r_i, y, color);
		y++;
	}
}

void	draw_door(t_data *data, int r_i, double top_pix, double bot_pix)
{
	int		color;
	double	y;
	double	offset_x;
	double	offset_y;

	color = 0;
	y = top_pix;
	offset_x = 0;
	offset_y = 0;
	while (y < bot_pix)
	{
		if (data->ray[r_i]->horizontal_hitt)
			offset_x = (int)data->ray[r_i]->wall_hitt_x % TILE_SIZE;
		if (data->ray[r_i]->vertical_hitt)
			offset_x = (int)data->ray[r_i]->wall_hitt_y % TILE_SIZE;
		offset_y = (y - data->ray[r_i]->top_wall) * (TILE_SIZE / data->ray[r_i]
				->wall_height);
		color = texture_door_pixel_color(data, offset_x, offset_y);
		(data->hold_lamp % 2 != 0)
				&& (color = color | (5 << 24));
		mlx_put_pixel(data->window->img, r_i, y, color);
		y++;
	}
}

void	draw(t_data *data, int r_i, double top_pix, double bot_pix)
{
	(data->hold_lamp % 2 != 0)
		&& (data->lum = 100 - data->ray[r_i]->ray_dst / 50);
	(data->hold_lamp % 2 == 0)
		&& (data->lum = 100 - data->ray[r_i]->ray_dst / 10);
	(data->lum < 0) && (data->lum = 0);
	if (data->ray[r_i]->element_hitt == '1')
		draw_walls(data, r_i, top_pix, bot_pix);
	else
		draw_door(data, r_i, top_pix, bot_pix);
	draw_f_c(data, r_i, top_pix, bot_pix);
}
