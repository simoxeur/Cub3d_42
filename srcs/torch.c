/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:05:45 by mbenchel          #+#    #+#             */
/*   Updated: 2024/11/24 14:56:42 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	toggle_lamp_off(t_data *data, int frame)
{
	if (data->hold_lamp % 2 == 0)
	{
		if (data->hold_lamp == 0)
			frame = 0;
		else if (frame > 0)
			frame--;
	}
	else
	{
		frame++;
		if (frame > 5)
			frame = 1;
	}
	return (frame);
}

void	render_torch(t_data *data)
{
	static int			frame = 0;
	static mlx_image_t	*cur_img = NULL;
	static double		last_t = 0;
	double				cur_t;

	cur_t = mlx_get_time();
	if (cur_t - last_t < 0.1)
		return ;
	if (cur_img)
		mlx_delete_image(data->window->mlx, cur_img);
	frame = toggle_lamp_off(data, frame);
	cur_img = load_frame(data, data->torch_frames[frame]);
	if (!cur_img)
		return (clean_close(data));
	mlx_image_to_window(data->window->mlx, cur_img, 550, 150);
	last_t = cur_t;
}
