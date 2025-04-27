/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:18:29 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 15:37:58 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_hook(mlx_key_data_t key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		mlx_terminate(data->window->mlx);
		clean_close(data);
		exit(0);
	}
	(key.key == MLX_KEY_M && key.action == MLX_PRESS) && (data->mouse_move++);
	if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
	{
		data->hold_lamp++;
		render(data);
	}
	(key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		&& (data->player->step_size < 20) && (data->player->step_size++);
	(key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		&& (data->player->step_size > 20) && (data->player->step_size--);
}
