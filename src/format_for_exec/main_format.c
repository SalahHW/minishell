/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:44:42 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/17 17:31:12 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_create_list(t_shell *shell)
{
	t_token	*tmp;

	tmp = shell->tokens->head;
	while (tmp)
	{
		if (tmp->type == t_cmd)
		ft_execadd_back(shell, ft_new_execlist_node(tmp));
		tmp = tmp->next;
	}
	return (0);
}

int	format_for_exec(t_shell *shell)
{
	printf("format_for_exec\n");
	if (ft_create_list(shell) == 1)
		return (1);
	printf("redirpipes\n");
	// ERR create execlist
	if (redir_pipes(shell) == 1)
		return (1);
	printf("redirfd\n");
	// ERR redir pipes
	if (ft_redirections(shell) == 1)
		return (1);
	// ERR redir fd

	return (0);
}