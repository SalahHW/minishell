/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_putxnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:27:55 by aherrman          #+#    #+#             */
/*   Updated: 2023/06/05 18:50:51 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_recur(unsigned int n, int nb_chiffre, int x)
{
	if (n > 0)
	{
		if (ft_recur(n / 16, nb_chiffre - 1, x) == -1)
			return (-1);
		if (n % 16 <= 9)
		{
			if (pft_putc((n % 16) + '0') == -1)
				return (-1);
		}
		else if (x == 1)
		{
			if (pft_putc((n % 16) + 'A' - 10) == -1)
				return (-1);
		}
		else if (x == 0)
		{
			if (pft_putc((n % 16) + 'a' - 10) == -1)
				return (-1);
		}
	}
	return (0);
}

int	pft_putxnb(unsigned int n, int x)
{
	unsigned int	nb;
	unsigned int	temp;
	int				nb_chiffre;

	temp = 0;
	nb = 0;
	nb_chiffre = 0;
	if (n == 0)
	nb_chiffre = pft_putc('0');
	else if (n <= 0)
	{
		nb_chiffre = pft_putc('-');
		temp = -n;
	}
	else
		temp = n;
	nb = temp;
	nb_chiffre += pft_compteur(temp, 16);
	if (ft_recur(nb, nb_chiffre, x) == -1)
		return (-1);
	return (nb_chiffre);
}
