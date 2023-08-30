/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_putunb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:27:55 by aherrman          #+#    #+#             */
/*   Updated: 2023/01/09 14:03:06 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_recur(unsigned int n, int nb_chiffre)
{
	if (n > 0)
	{
		if (ft_recur(n / 10, nb_chiffre - 1) == -1)
			return (-1);
		if (pft_putc((n % 10) + 48) == -1)
			return (-1);
	}
	return (0);
}

int	pft_putunb(unsigned int n)
{
	unsigned int	temp;
	int				nb_chiffre;

	nb_chiffre = 0;
	temp = 0;
	if (n == 0)
	{
		nb_chiffre = pft_putc('0');
	}
		temp = n;
		nb_chiffre += pft_compteur(temp, 10);
	if (ft_recur(n, nb_chiffre) == -1)
		return (-1);
	return (nb_chiffre);
}
