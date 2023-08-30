/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:35:55 by aherrman          #+#    #+#             */
/*   Updated: 2023/03/04 11:58:28 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

static int	ft_tri(const char *attribut, va_list list)
{
	int	nb_char ;

	nb_char = 0;
	if (*attribut == 'c')
		nb_char = pft_putc((char)va_arg(list, int));
	else if (*attribut == 's')
		nb_char = pft_puts((char *)va_arg(list, char *));
	else if (*attribut == 'p')
		nb_char += pft_putpnb(va_arg(list, unsigned long long int), 0);
	else if (*attribut == 'u')
		nb_char = pft_putunb((unsigned int)va_arg(list, unsigned int));
	else if ((*attribut == 'i') || (*attribut == 'd'))
		nb_char = pft_putnb((int)va_arg(list, int));
	else if (*attribut == 'x')
		nb_char = pft_putxnb((unsigned int)va_arg(list, unsigned int), 0);
	else if (*attribut == 'X')
		nb_char = pft_putxnb((unsigned int)va_arg(list, unsigned int), 1);
	else
		nb_char += write(1, attribut, 1);
	return (nb_char);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		nb_char;
	int		temp;

	va_start (list, format);
	nb_char = 0;
	while ((*format) != '\0')
	{
		if (*format != '%')
		{
			if (pft_putc(*format) == -1)
				return (-1);
			nb_char++;
		}
		else
		{
			temp = ft_tri(++format, list);
			if (temp == -1)
				return (-1);
			nb_char += temp;
		}
		format++;
	}
	va_end(list);
	return (nb_char);
}
