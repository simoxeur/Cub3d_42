/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:23:45 by mtalbi            #+#    #+#             */
/*   Updated: 2024/10/15 13:53:07 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_path(t_data *data, char *str)
{
	char	*path;

	path = str;
	if (!str || !*str || *str == '.')
		return (1);
	while (str && *str && *str != '.')
		str++;
	if (str++ && !*str)
		return (1);
	if (!ft_strncmp("cub", str, 3))
		return (data->map_path = path, 0);
	else
		return (1);
}

int	try_open(t_data *data)
{
	int	fd;

	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	else
		return (data->fd = fd, 0);
}
