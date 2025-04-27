/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:26:52 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/23 11:31:39 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../cub3d.h"

typedef struct s_data		t_data;
typedef struct s_allocate	t_allocate;

int		parse(t_data *data, char *argv);
int		check_path(t_data *data, char *str);
int		try_open(t_data *data);
int		get_data(t_data *data);
int		elemets_valid(t_data *data);
int		repete_data(t_data *data, char direction);
int		get_map(t_data *data, char *line);
int		new_map(t_data *data);
int		map_parse(t_data *data);
int		street_spaces(t_data *data);
int		walls_belongs(t_data *data);
int		col_atoa(char *str);
int		find_player(t_data *data, int *x, int *y);
void	flood_fill(t_data *data);
int		start(char *line);
int		end(char *line);
int		skiped_sp(char *str);
int		sep_nb(char *str, char separator);

// bonus parse
int		door_parse(t_data *data);

#endif