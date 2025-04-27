/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:12:08 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/13 14:20:51 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	fill(t_data *data, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_y < 0 || pos_y >= data->h
		|| pos_x >= (int)ft_strlen(data->map[pos_y], '\0')
		|| (data->filled_map[pos_y][pos_x] != '0'
		&& data->filled_map[pos_y][pos_x] != '1'
		&& data->filled_map[pos_y][pos_x] != 'N'
		&& data->filled_map[pos_y][pos_x] != 'S'
		&& data->filled_map[pos_y][pos_x] != 'E'
		&& data->filled_map[pos_y][pos_x] != 'W'
		&& data->filled_map[pos_y][pos_x] != 'D'
		&& data->filled_map[pos_y][pos_x] != 'd'))
		return ;
	data->filled_map[pos_y][pos_x] = 'F';
	fill(data, pos_x + 1, pos_y);
	fill(data, pos_x - 1, pos_y);
	fill(data, pos_x, pos_y + 1);
	fill(data, pos_x, pos_y - 1);
}

void	flood_fill(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = 0;
	pos_y = 0;
	if (find_player(data, &pos_x, &pos_y))
		return ;
	fill(data, pos_x, pos_y);
}
