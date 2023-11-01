/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:51:20 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/01 08:26:20 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*tokenize_operator(char **input)
{
	char	*token_start;
	char	*token_end;
	char	*new_token;
	char	*input_ptr;

	token_start = *input;
	token_end = *input;
	input_ptr = *input;
	if (*input_ptr == '>' || *input_ptr == '<' || *input_ptr == '|')
	{
		if (*input_ptr != '|' && *(input_ptr + 1) && *(input_ptr
				+ 1) == *input_ptr)
			token_end = input_ptr + 2;
		else
			token_end = input_ptr + 1;
	}
	new_token = get_str(token_start, token_end);
	*input = token_end;
	return (new_token);
}
