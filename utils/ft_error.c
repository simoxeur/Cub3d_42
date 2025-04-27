/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:29:33 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/16 12:18:17 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_error(int err_no)
{
	if (err_no == 0)
		write(2, "\033[0;31musage: ./cub3D file.cub\n\033[0m", 35);
	if (err_no == 1)
		write(2, "\033[0;31mthe path should be in form: file.cub\n\033[0m", 48);
	if (err_no == 2)
		write(2, "\033[0;31mthe file does not exist\n\033[0m", 35);
	if (err_no == 3)
		write(2, "\033[0;31mtexture path invalid\n\033[0m", 32);
	if (err_no == 4)
		write(2, "\033[0;31mcolor input invalid\n\033[0m", 31);
	if (err_no == 5)
		write(2, "\033[0;31mthere is an invalid line in the file\n\033[0m", 48);
	if (err_no == 6)
		write(2, "\033[0;31mmap error\nmake sure the map \
is respect the rules.\n\033[0m", 61);
	if (err_no == 7)
		write(2, "\033[0;31mthere is a repete data in the file\n\033[0m", 46);
	if (err_no == 8)
		write(2, "\033[0;31mthere is many player\n\033[0m", 32);
	if (err_no == 9)
		write(2, "\033[0;31mdoors should be between walls\n\033[0m", 41);
	if (err_no == 99)
		write(2, "\033[0;31mallocation failed\n\033[0m", 29);
}
