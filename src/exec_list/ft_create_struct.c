/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:13:58 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/09 09:55:49 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_create_list(t_token *token, t_exec *new)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		ft_execadd_back(new, ft_new_execlist_node(tmp));
		tmp = tmp->next;
	}
	return (0);
}

int	ft_create_struct(t_exec *exec, t_shell *shell)
{
    exec->general = shell->general;
	return (0);
}