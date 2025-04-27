/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:56:00 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 15:56:21 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	render3d(t_data *data)
{
	double	bot_pix;
	double	top_pix;
	int		i;

	i = 0;
	while (i < N_RAYS)
	{
		data->ray[i]->ray_dst *= cos(data->ray[i]->ray_angle
				- data->player->angle);
		data->ray[i]->wall_height = (TILE_SIZE / data->ray[i]->ray_dst)
			* ((WIDTH / 2) / tan((FOV / 2) * (M_PI / 180)));
		bot_pix = (HEIGHT / 2) + (data->ray[i]->wall_height / 2);
		top_pix = (HEIGHT / 2) - (data->ray[i]->wall_height / 2);
		data->ray[i]->top_wall = top_pix;
		data->ray[i]->bot_wall = bot_pix;
		bot_pix = fmin(bot_pix, HEIGHT);
		top_pix = fmax(top_pix, 0);
		draw(data, i, top_pix, bot_pix);
		i++;
	}
	return (0);
}
