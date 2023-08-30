/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:15:44 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/09 12:17:03 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a >= 'A' && a <= 'Z')
		|| (a >= 'a' && a <= 'z') || (a >= '0' && a <= '9'))
		return (1);
	else
		return (0);
}
int	ft_isalpha(int a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return (1);
	else
		return (0);
}

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
		return (1);
	else
		return (0);
}
int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}

int	ft_isprint(int a)
{
	if (a > 126 || a < 32)
		return (0);
	else
		return (1);
}