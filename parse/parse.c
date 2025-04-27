/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:25:41 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/18 19:44:29 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	parse(t_data *data, char *argv)
{
	if (check_path(data, argv))
		return (data->err_no = 1, 1);
	if (try_open(data))
		return (data->err_no = 2, 1);
	if (get_data(data))
		return (1);
	if (map_parse(data))
		return (1);
	if (door_parse(data))
		return (1);
	return (0);
}
