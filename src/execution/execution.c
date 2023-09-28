/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:38:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/28 13:57:16 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	execute_cmd(t_shell *shell)
{
	t_token	*token;

	token = shell->tokens->head;
	while (token)
	{
		if (token->type == t_cmd)
		{
			if (ft_strncmp(token->value, "cd", 3) == 0)
			{
				if (token->next && token->next->value && token->next->is_valid)
					ft_cd(token->next->value, shell->mini->env,
						shell->mini->home);
				ft_cd(NULL, shell->mini->env, shell->mini->home);
			}
			if (ft_strncmp(token->value, "pwd", 4) == 0)
				pwd();
			if (ft_strncmp(token->value, "exit", 5) == 0)
				shell->status = 0;
			token = token->next;
		}
	}
	return (1);
}
