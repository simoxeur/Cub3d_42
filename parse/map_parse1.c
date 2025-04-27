/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:16:15 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/13 14:22:26 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_lateral(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->h)
	{
		if (data->map[i][start(data->map[i])] != '1'
			|| data->map[i][end(data->map[i])] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	is_walled(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != '1' && map_line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	player_rep(t_data *data)
{
	int	rep;
	int	i;
	int	j;

	rep = 0;
	i = 0;
	j = 0;
	while (j < data->h)
	{
		i = 0;
		while (i < data->w)
		{
			if (data->map[j][i] == 'N' || data->map[j][i] == 'S'
				|| data->map[j][i] == 'E' || data->map[j][i] == 'W')
				rep++;
			i++;
		}
		j++;
	}
	if (rep != 1)
		return (1);
	return (0);
}

int	map_parse(t_data *data)
{
	if (new_map(data))
		return (1);
	if (elemets_valid(data))
		return (data->err_no = 6, 1);
	if (is_walled(data->map[0]))
		return (1);
	if (is_walled(data->map[data->h - 1]))
		return (data->err_no = 6, 1);
	if (check_lateral(data))
		return (data->err_no = 6, 1);
	if (street_spaces(data))
		return (data->err_no = 6, 1);
	if (walls_belongs(data))
		return (data->err_no = 6, 1);
	if (player_rep(data))
		return (data->err_no = 8, 1);
	return (0);
}
