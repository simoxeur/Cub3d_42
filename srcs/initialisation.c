/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:39:21 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 17:25:49 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	player_direction(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->h)
	{
		i = 0;
		while (i < (int)ft_strlen(data->map[j], '\0'))
		{
			(data->map[j][i] == 'N') && (data->player->angle = 3 * M_PI_2);
			(data->map[j][i] == 'S') && (data->player->angle = M_PI_2);
			(data->map[j][i] == 'E') && (data->player->angle = 0);
			(data->map[j][i] == 'W') && (data->player->angle = M_PI);
			i++;
		}
		j++;
	}
	return (0);
}

mlx_image_t	*load_frame(t_data *data, mlx_texture_t *texture)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(data->window->mlx, texture);
	if (!image)
		return (error_mlx(data), NULL);
	mlx_resize_image(image, 700, 700);
	return (image);
}

void	load_torch_frames(t_data *data)
{
	int		i;
	char	*path;
	char	*txt_index;

	i = -1;
	data->torch_frames = ft_malloc(&data->allocation,
			sizeof(mlx_texture_t *) * 6);
	while (++i < 6)
		data->torch_frames[i] = NULL;
	i = -1;
	while (++i < 6)
	{
		txt_index = ft_itoa(i);
		path = ft_strjoin("./torch/", txt_index);
		add_address(&data->allocation, path);
		path = ft_strjoin(path, "Torch_Sheet.png");
		add_address(&data->allocation, path);
		if (texture_valid(path))
			return (my_puts("invalid texture", 2),
				free(txt_index), clean_close(data));
		data->torch_frames[i] = mlx_load_png(path);
		if (!data->torch_frames[i])
			return (free(txt_index), clean_close(data));
		free(txt_index);
	}
}

void	init_values_2(t_data *data)
{
	data->mouse_move = 0;
	data->lum = 100;
	data->f_lum = 0;
	data->c_lum = 100;
	data->hold_lamp = 0;
}

int	init_values(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->window = ft_malloc(&data->allocation, sizeof(t_wind));
	data->player = ft_malloc(&data->allocation, sizeof(t_player));
	data->ray_utils = ft_malloc(&data->allocation, sizeof(t_ray_utils));
	if (!data->window || !data->player || !data->ray_utils)
		return (1);
	data->window->x = 0;
	data->window->y = 0;
	find_player(data, &x, &y);
	player_direction(data);
	data->player->step_size = 5;
	data->player->turn_speed = 0.03;
	data->player->x = (((double)x * TILE_SIZE) + TILE_SIZE / 2);
	data->player->y = (((double)y * TILE_SIZE) + TILE_SIZE / 2);
	init_values_2(data);
	if (init_texture(data))
		return (1);
	return (0);
}
