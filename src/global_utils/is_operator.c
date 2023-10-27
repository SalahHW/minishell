/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:26:34 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/26 06:48:16 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_operator(char c)
{
	if (is_redirection(c) || is_pipe(c))
		return (1);
	return (0);
}

int	is_redirection(char c)
{
	if (is_redirect_in(c) || is_redirect_out(c))
		return (1);
	return (0);
}

int	is_redirect_in(char c)
{
	if (c == '<')
		return (1);
	return (0);
}

int	is_redirect_out(char c)
{
	if (c == '>')
		return (1);
	return (0);
}

int	is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}
