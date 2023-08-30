/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:26:04 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/09 12:26:54 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	size_t	y;

	i = 0;
	y = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)(s + y));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (copy == 0)
		return (0);
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if ((!s) || (!f))
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	size_t	rlen;

	if (!s1 || !s2)
		return (0);
	rlen = (ft_strlen(s1) + ft_strlen(s2) + 1);
	copy = malloc(sizeof(*s1) * rlen);
	if (copy == 0)
		return (0);
	ft_strlcpy(copy, s1, rlen);
	ft_strlcat(copy, s2, rlen);
	return (copy);
}
size_t	ft_strlcat(char *dest, const char *src, size_t len)

{
	size_t idest;
	size_t isrc;
	size_t ret;
	size_t i;

	i = 0;
	if ((!dest) && (len == 0))
		return (0);
	idest = ft_strlen(dest);
	isrc = ft_strlen(src);
	if (len == 0)
		return (isrc);
	else if (len < idest)
		ret = len + isrc;
	else
		ret = idest + isrc;
	while ((len - 1 > idest + i) && (src[i] != '\0'))
	{
		dest[idest + i] = src[i];
		i++;
	}
	if (i < len)
		dest[idest + i] = '\0';
	return (ret);
}