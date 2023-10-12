/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:07:11 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/12 14:06:03 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	read_user_input(t_shell *shell)
{
	char	*input;

	while (shell->general->status)
	{
		input = readline(shell->prompt);
		if (input)
		{
			if (*input)
				add_history(input);
			if (!g_sigquit_received)
			{
				shell->tokens = tokenizer(input);
				if (!parser(shell->tokens))
				{
				}
				execute_cmd(shell);
			}
			free(input);
			if (!g_sigquit_received)
				clear_tokens_list(shell->tokens);
		}
		if (!input)
			shell->general->status = 0;
	}
	clear_history();
}
