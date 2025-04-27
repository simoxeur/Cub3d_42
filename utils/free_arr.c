/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:28:42 by mtalbi            #+#    #+#             */
/*   Updated: 2024/09/25 10:29:16 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_arr(char **arr, int lines)
{
	int	i;

	i = 0;
	if (lines == 0)
		return ;
	while (arr[i] && lines)
	{
		free(arr[i]);
		i++;
		lines--;
	}
	free(arr);
}
