/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:18:13 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/20 16:22:34 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	crached_space(t_data *data, int y, int x)
{
	if (x < (int)ft_strlen(data->map[y], '\0') - 1)
		if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != ' ')
			return (1);
	if (x > 0)
		if (data->map[y][x - 1] != '1' && data->map[y][x - 1] != ' ')
			return (1);
	if (y > 0 && x < (int)ft_strlen(data->map[y - 1], '\0'))
		if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != ' ')
			return (1);
	if (y < data->h - 1 && x < (int)ft_strlen(data->map[y + 1], '\0'))
		if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
			return (1);
	return (0);
}

int	street_spaces(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->h && data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == ' ')
			{
				if (crached_space(data, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
