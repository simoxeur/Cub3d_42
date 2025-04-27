/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:56:33 by mbenchel          #+#    #+#             */
/*   Updated: 2024/11/24 16:27:06 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	small_line(t_data *data, int radius, int color)
{
	int	y;
	int	rot_x;
	int	rot_y;

	y = 0;
	while (y <= 2 * radius)
	{
		rot_x = 125 + y * cos(data->player->angle);
		rot_y = 125 + y * sin(data->player->angle);
		if (rot_x >= 0 && rot_y >= 0)
			mlx_put_pixel(data->window->img, rot_x, rot_y, color);
		y++;
	}
}

void	circle(t_data *data, int radius, int color)
{
	int	x;
	int	y;
	int	circle_x;
	int	circle_y;

	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				circle_x = 125 + x;
				circle_y = 125 + y;
				if (circle_x >= 0 && circle_y >= 0)
					mlx_put_pixel(data->window->img, circle_x, circle_y, color);
			}
			x++;
		}
		y++;
	}
	small_line(data, radius, color);
}

int	clamp_value(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}

void	render_px_at(t_data *data, int x, int y)
{
	int	scaled_tile_x;
	int	scaled_tile_y;

	scaled_tile_x = (x * 3 + ((int)data->player->x - 125 * 3)) / TILE_SIZE;
	scaled_tile_y = (y * 3 + ((int)data->player->y - 125 * 3)) / TILE_SIZE;
	scaled_tile_x = clamp_value(scaled_tile_x, 0, data->w - 1);
	scaled_tile_y = clamp_value(scaled_tile_y, 0, data->h - 1);
	if (scaled_tile_x >= 0 && scaled_tile_y >= 0
		&& scaled_tile_x < data->w && scaled_tile_y < data->h)
	{
		if (data->map[scaled_tile_y][scaled_tile_x] == '1')
			mlx_put_pixel(data->window->img, x, y, 0x004703FF);
		else if (data->map[scaled_tile_y][scaled_tile_x] == 'D')
			mlx_put_pixel(data->window->img, x, y, 0x728200FF);
		else
			mlx_put_pixel(data->window->img, x, y, 0x0A1E05FF);
	}
}

void	render_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 250)
	{
		y = 0;
		while (y < 250)
		{
			render_px_at(data, x, y);
			y++;
		}
		x++;
	}
	circle(data, 7, 0xFF0000FF);
}
