/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:22:08 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/07 05:37:55 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// static int	setup_sigquit(void)
// {
// 	struct sigaction	sa;
//
// 	g_sigquit_received = 0;
// 	sa.sa_handler = SIG_IGN;
// 	sa.sa_flags = 0;
// 	sigemptyset(&sa.sa_mask);
// 	if (sigaction(SIGQUIT, &sa, NULL) == -1)
// 	{
// 		perror("Can't set SIGQUIT handler");
// 		return (-1);
// 	}
// 	return (0);
// }
//
// static int	setup_read_signal_handlers(void)
// {
// 	struct sigaction	sa;
//
// 	sa.sa_handler = &read_sig_handler;
// 	sa.sa_flags = 0;
// 	sigemptyset(&sa.sa_mask);
// 	if (sigaction(SIGINT, &sa, NULL) == -1)
// 		return (-1);
// 	return (0);
// }

void	signal_handlers(t_signal_status status)
{
	if (status == DEFAULT)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (status == IGNORE)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (status == READ)
	{
		rl_catch_signals = 1;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, &read_sig_handler);
	}
}
