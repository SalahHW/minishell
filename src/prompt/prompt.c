/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:07:11 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/11 01:31:17 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void read_user_input(t_shell *shell)
{
	char *input;

	while (shell->status)
	{
		input = readline(shell->prompt);
		if (input)
		{
			shell->tokens = extract_tokens(input);
			free(input);
			free_tokens(shell->tokens);
		}
	}
}
