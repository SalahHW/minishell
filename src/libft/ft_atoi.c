/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:01:29 by aherrman          #+#    #+#             */
/*   Updated: 2022/11/15 09:02:07 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static	void	ft_tri(const char *str, int *signe, int *i)
{
	while ((str[*i] == '\f') || (str[*i] == '\n') || (str[*i] == ' ')
		|| (str[*i] == '\r') || (str[*i] == '\t') || (str[*i] == '\v'))
	{
		(*i)++;
	}
	if (str[*i] == '-')
	{
	*signe *= -1;
	(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

int	ft_atoi(const char *str)
{
	int			signe;
	int			i;
	long int	nb;

	nb = 0;
	i = 0;
	signe = 1;
	ft_tri(str, &signe, &i);
	while ((str[i] >= 48) && (str[i] <= '9'))
	{
	nb += str[i] -48;
	nb *= 10;
	i++;
	}
	nb *= signe;
	return (nb / 10);
}
