/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:27:17 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/09 12:28:08 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = ft_strlen(src);
	if (len == 0)
		return (y);
	else
	{
		while ((len - 1 > i) && (src[i] != '\0'))
		{
		dest[i] = src[i];
		i++;
		}
	}
	dest[i] = '\0';
	return (y);
}
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*copy;
	size_t	i ;

	i = 0;
	if ((!s) || (!f))
		return (NULL);
	copy = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (copy == NULL)
		return (NULL);
	while (s[i])
	{
		copy[i] = f(i, s[i]);
			i++;
	}
	return (copy);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n -1) && ((unsigned char)s1[i] != 0)
		&& ((unsigned char)s2[i] != '\0'))
	{
		if ((unsigned char)(s1[i] - s2[i]) == 0)
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while ((len > i) && (haystack[i] != '\0'))
	{
		j = 0;
		while (((haystack[i + j] == needle[j]) && (haystack[i + j])
				&& (len > i + j)) || (needle[j] == '\0'))
		{
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
			j++;
		}
		i++;
	}
	return (NULL);
}