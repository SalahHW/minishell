/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:07:11 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 16:02:59 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	read_user_input(t_shell *shell)
{
	char	*input;
	int		status_code;

	while (shell->general->status)
	{
		signal_handlers(READ);
		input = readline(shell->prompt);
		if (input)
		{
			if (*input)
				add_history(input);
			tokenizer(input, shell);
			status_code = analyze_tokens(shell->tokens);
			if (!status_code)
				execute_cmd(shell);
			else
				shell->last_exit_code = status_code;
			free(input);
			clear_tokens_list(shell->tokens);
		}
		if (!input)
			shell->general->status = 0;
	}
	clear_history();
}
