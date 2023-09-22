/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:40:17 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/22 03:59:39 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

volatile sig_atomic_t	g_sigquit_received;

static int	init_prompt(t_shell *shell)
{
	char	*prompt_str;

	prompt_str = ft_strdup("minishell $ ");
	if (!prompt_str)
	{
		perror("Memory allocation error");
		return (-1);
	}
	shell->prompt = prompt_str;
	return (0);
}

int	init_shell(t_shell *shell)
{
	shell->status = 1;
	if (init_prompt(shell) == -1)
		return (-1);
	g_sigquit_received = 0;
	setup_signal_handlers();
	return (0);
}
