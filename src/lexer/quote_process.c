/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:24:46 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/26 06:51:09 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	remove_quotes(t_token *token)
{
	char	*new_value;

	new_value = ft_substr(token->value, 1, ft_strlen(token->value) - 2);
	replace_token(token, new_value);
}
