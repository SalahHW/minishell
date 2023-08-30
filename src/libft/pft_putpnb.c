/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_putpnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:27:55 by aherrman          #+#    #+#             */
/*   Updated: 2023/06/05 18:51:13 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static void	ft_recur(unsigned long long int n, unsigned int nb_chiffre, int x)
{
	if (n > 0)
	{
		ft_recur(n / 16, nb_chiffre - 1, x);
		if (n % 16 <= 9)
			pft_putc((n % 16) + '0');
		else if (x == 1)
			pft_putc((n % 16) + 'A' - 10);
		else if (x == 0)
			pft_putc((n % 16) + 'a' - 10);
	}
}

int	pft_putpnb(unsigned long long int n, int x)
{
	unsigned long long int	temp;
	unsigned int			nb_chiffre;

	temp = 0;
	nb_chiffre = 0;
	if (write (1, "0x", 2) == -1)
		return (-1);
	if (n == 0)
	nb_chiffre = pft_putc('0');
	else if (n <= 0)
	{
		nb_chiffre = pft_putc('-');
		temp = -n;
	}
	else
		temp = n;
	while (temp != 0)
	{
		temp = temp / 16;
		nb_chiffre++;
	}
	ft_recur(n, nb_chiffre, x);
	return (nb_chiffre + 2);
}
