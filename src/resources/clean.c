/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:42:05 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/23 16:33:53 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_all_fd(t_shell *shell)
{
	t_token	*tmp;

	tmp = shell->tokens->head;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (tmp->type == t_file)
			close(tmp->fd);
		tmp = tmp->next;
	}
}

void	free_for_general(t_shell *shell)
{
	free_tab(shell->general->env);
	free_tab(shell->general->path);
	free_tab(shell->general->expt);
	free(shell->general->home);
	free(shell->general);
}

void	clean_shell(t_shell *shell)
{
	free_for_general(shell);
	free(shell->prompt);
}
