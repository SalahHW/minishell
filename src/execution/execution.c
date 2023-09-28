/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:38:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/28 11:48:49 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int execute_cmd(t_shell *shell, t_mini *mini, char *cmd)
{
	t_token *token;

	token = shell->tokens->head;
	while (token)
	{
		if (token->type == t_cmd)
		{
			if (ft_strncmp(cmd, "cd", 3) == 0)
			{
				ft_cd(token->next, mini->env, mini->home);
			}
		}
		token = token->next;
	}

}
