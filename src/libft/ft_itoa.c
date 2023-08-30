/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:09:23 by aherrman          #+#    #+#             */
/*   Updated: 2022/11/15 14:47:59 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	ft_recur(unsigned int nb, int nb_chiffre, char *copy)
{
	if (nb > 0)
	{
		ft_recur(nb / 10, nb_chiffre - 1, copy);
		copy[nb_chiffre] = ((nb % 10) + 48);
	}
}

static	int	ft_number(int n)
{
	int				i;
	unsigned int	temp;

	i = 0;
	temp = n;
	if (n < 0)
		temp = -n;
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*copy;
	int				i;

	i = ft_number(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		copy = ft_calloc(sizeof(char), (i + 2));
		if (copy == 0)
			return (0);
		nb = -n;
		copy[0] = '-';
	}
	else
	{
		nb = n;
		copy = ft_calloc(sizeof(char), (i + 1));
		if (copy == 0)
			return (0);
		i--;
	}
	ft_recur(nb, i, copy);
	return (copy);
}
