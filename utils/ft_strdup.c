/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtalbi <mtalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:32:18 by mtalbi            #+#    #+#             */
/*   Updated: 2024/10/21 16:50:45 by mtalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s1)
{
	size_t	slen;
	char	*result;

	slen = ft_strlen(s1, '\0');
	result = (char *)malloc(sizeof(char) * (slen + 1));
	if (!result)
		return (NULL);
	slen = 0;
	while (s1[slen])
	{
		result[slen] = s1[slen];
		slen++;
	}
	result[slen] = '\0';
	return (result);
}
