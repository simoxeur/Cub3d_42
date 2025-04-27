/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_atoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:11:09 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/24 13:33:40 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	sep_nb(char *str, char separator)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	while (++i < (int)ft_strlen(str, '\0'))
		if (str[i] == separator)
			nb++;
	return (nb);
}

int	col_atoa(char *str)
{
	int	res;

	res = 0;
	if (!str || !*str)
		return (-1);
	while (str && *str == ' ')
		str++;
	if (!*str)
		return (-1);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + (*str - '0');
		else if (*str == ' ')
			break ;
		else
			return (-1);
		str++;
	}
	while (*str == ' ' && str++)
		if (*str && *str != ' ')
			return (-1);
	if (res >= 0 && res <= 255)
		return (res);
	return (-1);
}
