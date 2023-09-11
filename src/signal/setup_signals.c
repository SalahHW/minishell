/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:22:08 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/11 16:19:15 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int setup_sigquit(void)
{
	struct sigaction	sa;

	g_sigquit_received = 0;
	sa.sa_handler = &handle_sigquit;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
	{
		perror("Can't set SIGQUIT handler");
		return (-1);
	}
	return (0);
}

static int setup_sigint(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_sigint;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("Can't set SIGINT handler");
		return (-1);
	}
	return (0);
}

int	setup_signal_handlers(void)
{
	if (setup_sigquit() == -1)
		return (-1);
	if (setup_sigint() == -1)
		return (-1);
	return (0);
}
