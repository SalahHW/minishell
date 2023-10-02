/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:38:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/02 17:31:13 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_for_cmd(char *path, char **arg)
{
	int	pid;

	// cmd = /bin/ls
	// [arv[0] = ls arv[1] = -l ]
	// cmd = /bin/cat
	//  [arv[0] = cat arv[1] = -e arv[2] = -e ]
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
		if (execve(path, arg, NULL) == -1)
			return (1);
	return (0);
	// child process//
}

int	execute_cmd(t_shell *shell)
{
	t_token *token;
	printf("coucou\n");
	token = shell->tokens->head;
	while (token)
	{
		if (token->type == t_cmd)
		{
			if (ft_strncmp(token->value, "cd", 3) == 0)
			{
				if (token->next && token->next->value && token->next->is_valid)
				{
					ft_cd(token->next->value, shell->mini->env,
						shell->mini->home);
					pwd_change(shell->mini);
				}
			}
			if (ft_strncmp(token->value, "env", 4) == 0)
				env(shell->mini->env);
			if (ft_strncmp(token->value, "pwd", 4) == 0)
				pwd();
			if (ft_strncmp(token->value, "exit", 5) == 0)
				shell->status = 0;
			//if (ft_strncmp(token->value, "unset", 6) == 0)
				//unset(token->next->value, shell->mini);
			//if (ft_strncmp(token->value, "export", 7) == 0)
			//	ft_export(shell->mini, NULL);
		}
		token = token->next;
	}
	return (1);
}