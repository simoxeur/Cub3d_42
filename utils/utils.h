/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:34:00 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/20 13:01:43 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../cub3d.h"

void	ft_error(int err_no);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strchr(const char *s, int c);
char	*ft_duplicate(char *str);
char	*texture_duplicate(char *str);
int		ft_copy(char *dst, const char *src);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	free_arr(char **arr, int lines);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

#endif