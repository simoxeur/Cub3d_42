/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:34 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 17:07:33 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	texture_valid(char *texture)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	texture_cpy(t_data *data, char *line, char c)
{
	char	*texture;

	texture = add_address(&data->allocation,
			texture_duplicate(line + skiped_sp(line + 2) + 2));
	if (!texture)
		return (data->err_no = 99, 1);
	if (texture_valid(texture))
		return (data->err_no = 3, 1);
	if (repete_data(data, c))
		return (data->err_no = 7, 1);
	if (c == 'N')
		return (data->no_texture = texture, 0);
	else if (c == 'S')
		return (data->so_texture = texture, 0);
	else if (c == 'W')
		return (data->we_texture = texture, 0);
	else if (c == 'E')
		return (data->ea_texture = texture, 0);
	return (data->err_no = 3, 1);
}

int	color_cpy(t_data *data, char *line)
{
	char	*col_line;
	char	**col_arr;
	int		*color;
	int		i;

	col_line = add_address(&data->allocation,
			ft_duplicate(line + skiped_sp(line + 2) + 2));
	if (sep_nb(col_line, ',') != 2)
		return (data->err_no = 4, 1);
	col_arr = ft_split(col_line, ',');
	i = -1;
	color = (int *)ft_malloc(&data->allocation, 3 * sizeof(int));
	if (!col_line || !col_arr || !color)
		return (data->err_no = 99, 1);
	i = -1;
	while (++i < 3)
	{
		color[i] = col_atoa(col_arr[i]);
		if (color[i] == -1)
			return (data->err_no = 4, free_arr(col_arr, -1), 1);
	}
	free_arr(col_arr, -1);
	(line[0] == 'C') && (data->ceiling_color = color);
	(line[0] == 'F') && (data->floor_color = color);
	return (0);
}

int	check_line(t_data *data, char *line)
{
	static int	readed_data;

	if (readed_data >= 6)
		return (2);
	if (line[0] == '\n')
		return (0);
	else
	{
		readed_data++;
		if (!ft_strncmp("NO ", line + skiped_sp(line), 3))
			return (texture_cpy(data, line + skiped_sp(line), 'N'));
		else if (!ft_strncmp("SO ", line + skiped_sp(line), 3))
			return (texture_cpy(data, line + skiped_sp(line), 'S'));
		else if (!ft_strncmp("WE ", line + skiped_sp(line), 3))
			return (texture_cpy(data, line + skiped_sp(line), 'W'));
		else if (!ft_strncmp("EA ", line + skiped_sp(line), 3))
			return (texture_cpy(data, line + skiped_sp(line), 'E'));
		else if (!ft_strncmp("F ", line + skiped_sp(line), 2))
			return (color_cpy(data, line + skiped_sp(line)));
		else if (!ft_strncmp("C ", line + skiped_sp(line), 2))
			return (color_cpy(data, line + skiped_sp(line)));
	}
	return (data->err_no = 5, 1);
}

int	get_data(t_data *data)
{
	char	*line;
	int		ret_value;

	ret_value = 0;
	line = add_address(&data->allocation, get_next_line(data->fd));
	if (!line)
		return (data->err_no = 99, 1);
	if (check_line(data, line))
		return (1);
	while (line)
	{
		line = add_address(&data->allocation, get_next_line(data->fd));
		if (!line)
			return (data->err_no = 99, 1);
		ret_value = check_line(data, line);
		if (ret_value == 1)
			return (1);
		else if (ret_value == 2)
			break ;
	}
	if (get_map(data, line))
		return (1);
	return (0);
}
