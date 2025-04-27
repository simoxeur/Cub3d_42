/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:55:58 by mtalbi            #+#    #+#             */
/*   Updated: 2024/10/05 11:19:29 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (!str)
		str = "";
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (0);
}

int	ft_check_nl(char *str)
{
	int	nl;
	int	i;

	if (!str)
		str = "";
	i = 0;
	nl = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		else
			nl = 0;
		i++;
	}
	return (nl);
}

char	*ft_strnjoin(char const *str1, char const *str2, size_t n)
{
	char		*join;
	char		*result;
	const char	*ptr;
	const char	*s;

	s = str1;
	ptr = str2;
	if (!str1)
		str1 = "";
	if (!str2)
		return (NULL);
	join = (char *)malloc((ft_strlen(str1, '\0') + n + (size_t)1));
	if (!join)
	{
		if (str1 == s)
			free ((char *)str1);
		return (NULL);
	}
	result = join;
	while (*str1)
		*join++ = *str1++;
	while (*str2 && (str2 - ptr) < (long)n)
		*join++ = *str2++;
	*join = '\0';
	return (free((char *)s), result);
}
