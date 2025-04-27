/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:14:51 by mtalbi            #+#    #+#             */
/*   Updated: 2024/10/21 17:11:51 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	join_to_map(t_data *data, char *line)
{
	static int	cur_line;
	char		**new_map;
	int			i;

	i = 0;
	new_map = ft_malloc(&data->allocation, (cur_line + 1) * sizeof(char *));
	if (!new_map)
		return (data->err_no = 99, 1);
	new_map[cur_line] = add_address(&data->allocation, ft_duplicate(line));
	if (!new_map[cur_line])
		return (data->err_no = 99, 1);
	while (i < cur_line)
	{
		new_map[i] = data->map[i];
		i++;
	}
	data->map = new_map;
	cur_line++;
	data->h = cur_line;
	return (0);
}

int	get_map(t_data *data, char *line)
{
	while (line)
	{
		if (line[0] != '\n')
			break ;
		line = add_address(&data->allocation, get_next_line(data->fd));
		if (!line)
			return (data->err_no = 99, 1);
	}
	while (line)
	{
		if (join_to_map(data, line))
			return (1);
		line = add_address(&data->allocation, get_next_line(data->fd));
	}
	return (0);
}
