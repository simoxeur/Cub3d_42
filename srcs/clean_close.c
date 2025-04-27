/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:44:10 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 17:12:53 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	clean_close(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (data->torch_frames && data->torch_frames[i])
			mlx_delete_texture(data->torch_frames[i]);
	if (data->door_texture)
		mlx_delete_texture(data->door_texture);
	i = -1;
	while (++i < 4)
		if (data->wall_texture[i])
			mlx_delete_texture(data->wall_texture[i]);
	clean_up(&data->allocation);
	free(data);
	exit(0);
}
