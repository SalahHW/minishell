/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:40:17 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/07 06:00:29 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	init_general_data(t_shell *shell)
{
	shell->general->env = NULL;
	shell->general->pipes = NULL;
	shell->general->nbpipes = 0;
	shell->general->b_err = 0;
	return (0);
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
	shell->last_exit_code = 0;
	if (init_prompt(shell) == -1)
		return (-1);
	if (init_general_data(shell) == -1)
		return (-1);
	return (0);
}
