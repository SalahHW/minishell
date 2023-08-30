/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:28:34 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/09 12:30:27 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	y;

	y = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + y));
	while (y > 0)
	{
		if (s[y] == (char)c)
			return ((char *)(s + y));
		y--;
	}
	if (s[y] == (char)c)
		return ((char *)(s + y));
	return (NULL);
}
static size_t	ft_start(char const *s1, char const *set)
{
	size_t	c;

	c = 0;
	while (ft_strchr(set, s1[c]) != NULL)
	{
		c++;
	}
	return (c);
}

static size_t	ft_end(char const *s1, char const *set)
{
	size_t	c;

	c = ft_strlen(s1);
	while ((c > 0) && (ft_strchr(set, s1[c]) != NULL))
	{
		c--;
	}
	return (c + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const *copy;
	size_t start;
	size_t end;
	size_t rlen;

	if (set == NULL || s1 == NULL)
		return (NULL);
	if (*s1 == '\0')
		return (ft_calloc(1, sizeof(char)));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	rlen = (end - start + 1);
	if (start >= end)
		return (ft_calloc(1, sizeof(char)));
	copy = malloc(sizeof(char) * rlen);
	if (copy == 0)
		return (0);
	ft_strlcpy((char *)copy, &s1[start], rlen);
	return ((char *)copy);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	rlen;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_calloc(1, sizeof(char)));
	else if ((ft_strlen(s) - (size_t)(start)) < len)
		rlen = ft_strlen(s) - (size_t)(start);
	else
	rlen = len;
	rlen += 1;
	copy = malloc(sizeof(*s) * rlen + 1);
	if (copy == 0)
		return (NULL);
	ft_strlcpy(copy, &s[start], rlen);
	return (copy);
}