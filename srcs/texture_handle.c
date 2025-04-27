/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:02:30 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 17:12:04 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_texture(t_data *data)
{
	data->wall_texture[0] = mlx_load_png(data->no_texture);
	data->wall_texture[1] = mlx_load_png(data->so_texture);
	data->wall_texture[2] = mlx_load_png(data->ea_texture);
	data->wall_texture[3] = mlx_load_png(data->we_texture);
	if (!data->wall_texture[0] || !data->wall_texture[1]
		|| !data->wall_texture[2] || !data->wall_texture[3])
		return (error_mlx(data), 1);
	return (0);
}

int	texture_pixel_color(t_data *data, int x, int y, int d)
{
	uint8_t		*pixel;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

	if (x >= (int)data->wall_texture[d]->width || x < 0)
		x = 0;
	if (y >= (int)data->wall_texture[d]->height || y < 0)
		y = 0;
	pixel = (uint8_t *)&data->wall_texture[d]->pixels[((y
				* data->wall_texture[d]->width) + x) * 4];
	r = pixel[0] * data->lum / 100;
	g = pixel[1] * data->lum / 100;
	b = pixel[2] * data->lum / 100;
	a = pixel[3];
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

int	texture_door_pixel_color(t_data *data, int x, int y)
{
	uint8_t		*pixel;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		a;

	if (x >= (int)data->door_texture->width || x < 0)
		x = 0;
	if (y >= (int)data->door_texture->height || y < 0)
		y = 0;
	pixel = (uint8_t *)&data->door_texture->pixels[((y
				* data->door_texture->width) + x) * 4];
	r = pixel[0] * data->lum / 100;
	g = pixel[1] * data->lum / 100;
	b = pixel[2] * data->lum / 100;
	a = pixel[3];
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
