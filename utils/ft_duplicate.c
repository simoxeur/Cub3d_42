/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:26:42 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/18 20:13:12 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_duplicate(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (ft_check_nl(str))
		res = (char *)malloc(ft_strlen(str, '\0'));
	else
		res = (char *)malloc(ft_strlen(str, '\0') + 1);
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*texture_duplicate(char *str)
{
	char	*res;
	int		i;
	int		back_sp;

	i = 0;
	back_sp = ft_strlen(str, '\n') - 1;
	while (str[back_sp] && str[back_sp] == ' ')
		back_sp--;
	if (ft_check_nl(str))
		res = (char *)malloc(ft_strlen(str, '\0'));
	else
		res = (char *)malloc(ft_strlen(str, '\0') + 1);
	while (str[i] && str[i] != '\n' && i < back_sp + 1)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
