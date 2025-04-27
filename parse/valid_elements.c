/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:23:15 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/19 18:10:11 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	elemets_valid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->h)
	{
		j = 0;
		while (j < data->w)
		{
			if (data->map[i][j] != '1' && data->map[i][j] != '0'
			&& data->map[i][j] != ' ' && (data->map[i][j] != 'N'
			&& data->map[i][j] != 'S' && data->map[i][j] != 'E'
			&& data->map[i][j] != 'W' && data->map[i][j] != 'D'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	skiped_sp(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}
