/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:44:42 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/23 09:56:43 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_count_t_arg(t_token *token)
{
	t_token	*tmp;
	int		i;

	i = 1;
	tmp = token;
	while (tmp && tmp->type == t_arg)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

char	**ft_for_arg(t_token *token)
{
	t_token	*tmp;
	char	**arg;
	int		i;

	i = 1;
	arg = malloc(sizeof(char *) * (ft_count_t_arg(token->next) + 1));
	if (!arg)
		return (NULL);
	
	arg[0] = ft_strdup(token->value);
	tmp = token->next;
	while (tmp && tmp->type == t_arg)
	{
		arg[i] = ft_strdup(tmp->value);
		i++;
		tmp = tmp->next;
	}
	arg[i] = NULL;
	return (arg);
}

int	ft_format_for_tokens(t_shell *shell)
{
	t_token	*tmp;

	tmp = shell->tokens->head;
	while (tmp)
	{
		if (tmp->type == t_cmd)
		{
			tmp->cmd_path = ft_strdup(tmp->value);
			tmp->arg = ft_for_arg(tmp);
			if (tmp->cmd_path == NULL || tmp->arg == NULL)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
int	ft_create_list(t_shell *shell)
{
	t_token	*tmp;
	shell->execlist = NULL;
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
	if (ft_format_for_tokens(shell) == 1)
		return (1);
	// ERR format for tokens//
	if (ft_create_list(shell) == 1)
		return (1);
	print_execlist(shell->execlist);
	// ERR create execlist
	if (ft_redirections(shell) == 1)
		return (1);
printf("coucou");
	// ERR redir fd

	return (0);
}