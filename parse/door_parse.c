/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:02:14 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/19 18:12:12 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	door_valid(t_data *data, int x, int y)
{
	int	lat_wall;
	int	v;

	lat_wall = 0;
	v = 1;
	if (data->map[y][x - 1] == '1' && data->map[y][x + 1] == '1')
	{
		if (data->map[y - 1][x] == '1' || data->map[y + 1][x] == '1')
			v = 0;
		lat_wall++;
	}
	if (data->map[y - 1][x] == '1' && data->map[y + 1][x] == '1')
	{
		if (data->map[y][x - 1] == '1' || data->map[y][x + 1] == '1')
			v = 0;
		lat_wall++;
	}
	if (data->map[y][x + 1] == 'D' || data->map[y][x - 1] == 'D'
	|| data->map[y + 1][x] == 'D' || data->map[y - 1][x] == 'D')
		v = 0;
	v = v * lat_wall;
	if (v == 1)
		return (1);
	return (0);
}

int	door_parse(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->h)
	{
		i = 0;
		while (i < data->w)
		{
			if (data->map[j][i] == 'D')
				if (!door_valid(data, i, j))
					return (data->err_no = 9, 1);
			i++;
		}
		j++;
	}
	return (0);
}
