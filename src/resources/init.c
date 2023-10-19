/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:40:17 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/19 09:33:58 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

volatile sig_atomic_t	g_sigquit_received;

int init_general_data(t_shell *shell)
{
	shell->general->env = NULL;
	shell->general->path = NULL;
	shell->general->expt = NULL;
	shell->general->home = NULL;
	shell->general->pipes = NULL;
	shell->general->nbpipes = 0;
	return(0);
}

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
	shell->general = malloc(sizeof(t_general));
	shell->general->status = 1;
	if (init_prompt(shell) == -1)
		return (-1);
	if(init_general_data(shell) == -1)
		return (-1);
	g_sigquit_received = 0;
	setup_signal_handlers();
	return (0);
}
