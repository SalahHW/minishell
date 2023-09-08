/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:07:11 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/08 22:48:14 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void init_prompt(t_shell *shell)
{
	shell->status = 1;
	shell->prompt = ft_strdup("minishell $ ");
}

void read_user_input(t_shell *shell)
{
	char *input;

	input = readline(shell->prompt);
	shell->tokens = extract_tokens(input);
}
