/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:12:55 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/07 12:10:13 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

 char	*ft_name(int i)
{
	char	*name;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strdup("tmp");
	tmp2 = ft_itoa(i);
	name = ft_strjoin(tmp, tmp2);
	free(tmp);
	free(tmp2);
	return (name);
}

void	ft_heredoc(t_shell *shell)
{
	t_token *token;
	int i;
	 char *name;

	i = 0;
	token = shell->tokens->head;
	while (token)
	{
		if (token->type == t_file)
		{
			if (token->prev && token->prev->type == t_heredoc)
			{
				name = ft_name(i);
				ft_here_heredoc(token, shell, name);
				i++;
				free(name);
			}
		}
		token = token->next;
		if (token && token->type == t_pipe)
			shell->execlist = shell->execlist->next;
	}
}
