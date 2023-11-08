/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:36:46 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 04:34:26 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_execlist(t_execlist *execlist)
{
	t_execlist	*tmp2;

	if (execlist == NULL)
		return ;
	while (execlist)
	{
		tmp2 = execlist->next;
		free(execlist->cmd_path);
		free_tab(execlist->arg);
		free(execlist);
		execlist = tmp2;
	}
	free(execlist);
}

void	free_general_utils(t_general *general)
{
	int	i;

	i = 0;
	if (general->nbpipes != 0)
	{
		if (general->pipes != NULL)
		{
			while (i < general->nbpipes)
			{
				free(general->pipes[i]);
				i++;
			}
			free(general->pipes);
		}
	}
	free_tab(general->env);
	free(general->pids);
}

void	ft_free_exec(t_shell *shell)
{
	free_execlist(shell->execlist);
	free_general_utils(shell->general);
}
