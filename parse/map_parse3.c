/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:22:49 by mtalbi            #+#    #+#             */
/*   Updated: 2024/10/16 11:23:08 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	map_cpy(t_data *data)
{
	int	i;

	i = 0;
	data->filled_map = ft_malloc(&data->allocation, data->h * sizeof(char *));
	if (!data->filled_map)
		return (data->err_no = 99, 1);
	while (i < data->h)
	{
		data->filled_map[i] = add_address(&data->allocation,
				ft_duplicate(data->map[i]));
		if (!data->filled_map)
			return (data->err_no = 99, 1);
		i++;
	}
	return (0);
}

int	walls_belongs(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map_cpy(data))
		return (1);
	flood_fill(data);
	while (i < data->h)
	{
		j = 0;
		while (j < (int)ft_strlen(data->map[i], '\0'))
		{
			if (data->filled_map[i][j] != 'F' && data->filled_map[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	longest_line(t_data *data)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < data->h)
	{
		if (max < (int)ft_strlen(data->map[i], '\0'))
			max = (int)ft_strlen(data->map[i], '\0');
		i++;
	}
	return (max);
}

int	new_map(t_data *data)
{
	int		i;
	int		j;
	char	*tmp_line;

	i = 0;
	j = 0;
	tmp_line = NULL;
	data->w = longest_line(data);
	while (j < data->h)
	{
		i = (int)ft_strlen(data->map[j], '\0');
		tmp_line = data->map[j];
		data->map[j] = ft_malloc(&data->allocation, data->w + 1);
		if (!data->map[j])
			return (data->err_no = 99, 1);
		ft_copy(data->map[j], tmp_line);
		while (i < data->w)
		{
			data->map[j][i] = ' ';
			i++;
		}
		data->map[j][i] = '\0';
		j++;
	}
	return (0);
}
