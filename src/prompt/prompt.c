/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:07:11 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/22 05:28:19 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	read_user_input(t_shell *shell)
{
	char	*input;

	while (shell->status)
	{
		input = readline(shell->prompt);
		if (input)
		{
			if (*input)
				add_history(input);
			if (!g_sigquit_received)
				shell->tokens = extract_tokens(input);
			free(input);
			if (!g_sigquit_received)
				clear_tokens_list(shell->tokens);
		}
		if (!input)
			shell->status = 0;
	}
	clear_history();
}
