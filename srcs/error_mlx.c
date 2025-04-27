/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:38:37 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 13:43:02 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	error_mlx(t_data *data)
{
	my_puts((char *)mlx_strerror(mlx_errno), 2);
	clean_close(data);
	exit(EXIT_FAILURE);
}
