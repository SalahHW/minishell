/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:36:12 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/17 17:15:22 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"\

int	redir_pipes(t_shell *shell)
{
	int	i;

	i = 0;
	while (i < shell->general->nbpipes)
	{
		if (i == 0)
			shell->execlist->fd_out = shell->general->pipes[i][1];
		else if (i == shell->general->nbpipes - 1)
		{
			shell->execlist->fd_in = shell->general->pipes[i - 1][0];
			shell->execlist->fd_out = shell->general->pipes[i][1];
		}
		else
			(shell->execlist->fd_in = shell->general->pipes[i - 1][0]);
		i++;
		shell->execlist = shell->execlist->next;
	}
	return (0);
}

int	ft_malloc_pipe(int nbpipes, int **pipefd)
{
	int	i;

	i = 0;
	pipefd = malloc(sizeof(int *) * nbpipes);
	if (!pipefd)
		return (1);
	while (i < nbpipes)
	{
		pipefd[i] = malloc(sizeof(int) * 2);
		if (!pipefd[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_create_pipe(int nbpipe, t_shell *shell)
{
	int	i;

	i = 0;
	if (ft_malloc_pipe(nbpipe, shell->general->pipes))
		return (1);
	while (i < nbpipe)
	{
		if (pipe(shell->general->pipes[i]) == -1)
			return (1);
		i++;
	}
	return (0);
}
int	ft_general_pipe(t_shell *shell)
{
	t_token	*token;
	int		i;

	i = 0;
	token = shell->tokens->head;
	while (token)
	{
		if (token->type == t_pipe)
			i++;
		token = token->next;
	}
	shell->general->nbpipes = i;
	if (ft_create_pipe(shell->general->nbpipes, shell) == 1)
		return (1);
	return (0);
}
