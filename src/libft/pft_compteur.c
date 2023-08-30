/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pft_compteur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:42:53 by aherrman          #+#    #+#             */
/*   Updated: 2023/01/06 15:32:28 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include  "ft_printf.h"

int	pft_compteur(unsigned long long int n, int div)
{
	int	compteur;

	compteur = 0;
	while (n != 0)
	{
		n = n / div;
		compteur++;
	}
	return (compteur);
}
