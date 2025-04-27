/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:45:42 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/19 16:49:53 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	extract_color(int *col_arr, int lum)
{
	int	r;
	int	g;
	int	b;
	int	a;
	int	color;

	r = col_arr[0] * lum / 100;
	g = col_arr[1] * lum / 100;
	b = col_arr[2] * lum / 100;
	a = 255;
	color = (r << 24) | (g << 16) | (b << 8) | a;
	return (color);
}

int	darken_color(int color, float factor)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = (color >> 24 & 0xFF) * factor;
	g = (color >> 16 & 0xFF) * factor;
	b = (color >> 8 & 0xFF) * factor;
	a = 255;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
