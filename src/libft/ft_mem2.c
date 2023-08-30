/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:19:27 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/09 12:19:53 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0 || ((char *)dest == 0 && (char *)src == NULL))
		return (dest);
	if (dest > src)
	{
		while (len-- > 0)
		{
			*(char *)(dest + len) = *(char *)(src + len);
		}
	}
	else
	{
		while (i < len)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *) b;
	while (len > 0)
	{
	*temp = (unsigned char)c;
	temp++;
	len--;
	}
	return (b);
}