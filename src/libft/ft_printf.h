/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:43:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/05/02 08:52:06 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//*****lib*****//
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

//*****proto*****//
int	ft_printf(const char *format, ...);
int	pft_putc(char c);
int	pft_puts(char *s);
int	pft_putnb(int i);
int	pft_putunb(unsigned int i);
int	pft_putxnb(unsigned int i, int m);
int	pft_putpnb(unsigned long long int i, int m);
int	pft_compteur(unsigned long long int i, int div);
#endif
