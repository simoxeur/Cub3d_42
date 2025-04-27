/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchel <mbenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:33:36 by mtalbi            #+#    #+#             */
/*   Updated: 2024/11/22 18:08:53 by mbenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	intlen(long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*itoap(int len, long long n, char *str)
{
	int	neg;

	neg = 0;
	if (n < 0)
	{
		n *= -1;
		neg = 1;
		str[0] = '-';
	}
	str[len] = '\0';
	while (len > neg)
	{
		str[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*res;
	long long	nb;
	int			len;

	len = intlen(n);
	nb = n;
	if (n < 0)
		len = len + 1;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	itoap(len, n, res);
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*c;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1, '\0') + ft_strlen(s2, '\0');
	c = (char *)malloc(len + 1);
	if (c == NULL)
		return (NULL);
	while (s1[j])
		c[i++] = s1[j++];
	j = 0;
	while (s2[j])
		c[i++] = s2[j++];
	c[i] = '\0';
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s || start >= ft_strlen(s, '\0'))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s, '\0'))
		len = ft_strlen(s, '\0') - start;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (s[start] && i < len)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
