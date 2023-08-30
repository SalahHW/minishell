/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:20:18 by aherrman          #+#    #+#             */
/*   Updated: 2023/08/09 12:21:33 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
static void	ft_recur(unsigned int n, int nb_chiffre, int fd)
{
	if (n > 0)
	{
		ft_recur(n / 10, nb_chiffre - 1, fd);
		ft_putchar_fd(((n % 10) + 48), fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	unsigned int	temp;
	int				nb_chiffre;

	nb_chiffre = 0;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
	{		
		ft_putchar_fd('-', fd);
		temp = -n;
	}
	else
		temp = n;
	nb = temp;
	while (temp != 0)
	{
		temp = temp / 10;
		nb_chiffre++;
	}
	ft_recur(nb, nb_chiffre, fd);
}
void	ft_putstr_fd(char *c, int fd)
{
	size_t	i;

	i = 0;
	if (!c)
		return ;
	while (c[i])
	{
		ft_putchar_fd(c[i], fd);
		i++;
	}
}