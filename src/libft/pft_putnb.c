/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_putnb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:27:55 by aherrman          #+#    #+#             */
/*   Updated: 2023/01/06 15:49:49 by aherrman         ###   ########.fr       */
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

int	pft_putnb(int n)
{
	unsigned int	nb;
	unsigned int	temp;
	int				nb_chiffre;

	nb_chiffre = 0;
	temp = 0;
	nb_chiffre = 0;
	if (n == 0)
		nb_chiffre = pft_putc('0');
	else if (n < 0)
	{
		nb_chiffre = pft_putc('-');
		temp = -n;
	}
	else
		temp = n;
	nb = temp;
	if (nb_chiffre == -1)
		return (-1);
	nb_chiffre += pft_compteur(temp, 10);
	if (ft_recur(nb, nb_chiffre) == -1)
		return (-1);
	return (nb_chiffre);
}
