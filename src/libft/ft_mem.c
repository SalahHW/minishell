/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:17:58 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/09 12:18:59 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	s = malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, (size * count));
	return (s);
}
void	ft_bzero(void *b, size_t len)
{
	char	*temp;

	temp = (char *)b;
	while (len > 0)
	{
	*temp = '\0';
		temp++;
	len--;
	}	
}
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if ((n > 0) || ((*(unsigned char *)(s + i) == '\0') || (c == 0)))
	{
		while (n > i)
		{
			if (*(unsigned char *)(s + i) == (unsigned char)c)
				return ((void *)s + i);
		i++;
		}
	}
	return (NULL);
}
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if ((*(unsigned char *)(s1 + i) - (*(unsigned char *)(s2 + i))) == 0)
			i++;
		else
			return (*(unsigned char *)(s1 + i) - (*(unsigned char *)(s2 + i)));
	}
	return (*(unsigned char *)(s1 + i) - (*(unsigned char *)(s2 + i)));
}
void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*temp;

	temp = (char *)dest;
	if (temp == 0 && (char *)src == NULL)
		return (NULL);
	while (len > 0)
	{
	*(char *)dest = *(char *)src;
		dest++;
		src++;
	len--;
	}
	return (temp);
}