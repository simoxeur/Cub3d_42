/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:24:42 by mtalbi            #+#    #+#             */
/*   Updated: 2024/10/16 10:38:18 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	find_player(t_data *data, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < (int)ft_strlen(data->map[i], '\0'))
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
			|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				*x = j;
				*y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	start(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' && i < (int)ft_strlen(line, '\0'))
		i++;
	return (i);
}

int	end(char *line)
{
	int	i;

	i = ft_strlen(line, '\0') - 1;
	while (line[i] == ' ')
		i--;
	return (i);
}

int	repete_data(t_data *data, char direction)
{
	if (direction == 'N' && data->no_texture)
		return (1);
	if (direction == 'S' && data->so_texture)
		return (1);
	if (direction == 'E' && data->ea_texture)
		return (1);
	if (direction == 'W' && data->we_texture)
		return (1);
	return (0);
}
