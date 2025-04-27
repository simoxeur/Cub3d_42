/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:31:01 by mtalbi            #+#    #+#             */
/*   Updated: 2024/10/21 16:50:20 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_countword(char const *str, char c)
{
	size_t	count;
	int		r;

	count = 0;
	r = 1;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str == c)
		{
			str++;
			r = 1;
		}
		if (*str && *str != c && r == 1)
		{
			count++;
			r = 0;
		}
		if (*str)
			str++;
	}
	if (*str-- == c && !*str)
		count--;
	return (count);
}

static size_t	ft_wordlenght(char const *s, char c)
{
	size_t	len;
	char	*str;

	len = 0;
	str = (char *)s;
	if (!str)
		return (0);
	if (!ft_strchr(str, c))
		len = ft_strlen(str, '\0');
	else
		len = ft_strchr(str, c) - str;
	return (len);
}

static char	**ft_split_free(char **str, size_t index)
{
	while (index > 0)
	{
		free(str[index - 1]);
		index--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**result;

	if (!s)
		return (NULL);
	index = 0;
	result = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			result[index] = ft_substr(s, 0, ft_wordlenght(s, c));
			if (!result[index])
				return (ft_split_free(result, index));
			s += ft_wordlenght(s, c);
			index++;
		}
	}
	result[index] = NULL;
	return (result);
}
