/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:37:56 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 17:04:52 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	struct_init(t_data *data)
{
	data->map = NULL;
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->ea_texture = NULL;
	data->we_texture = NULL;
	data->d_texture = NULL;
	data->err_no = -1;
	data->allocation = NULL;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	struct_init(data);
	if (argc != 2 || parse(data, argv[1]))
		return (write(2, "ERROR\n", 6), ft_error(data->err_no),
			clean_up(&data->allocation), free(data), 1);
	if (graphic_handle(data))
		return (clean_close(data), 1);
	clean_close(data);
}
