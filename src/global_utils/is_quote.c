/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:29:53 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/01 20:52:43 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_quote(char c)
{
	if (is_single_quote(c) || is_double_quote(c))
		return (1);
	return (0);
}

int	is_single_quote(char c)
{
	if (c == '\'')
		return (1);
	return (0);
}

int	is_double_quote(char c)
{
	if (c == '\"')
		return (1);
	return (0);
}

// Return 1 if str contains a quote, 0 otherwise
int	has_quote(char *str)
{
	while (*str)
	{
		if (is_quote(*str))
			return (1);
		str++;
	}
	return (0);
}
