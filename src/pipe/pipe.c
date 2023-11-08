/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:36:12 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 04:35:39 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_define_out_pipe(t_shell *shell, int nbpipes)
{
	int	i;
	int	first;

	i = 0;
	first = 0;
	while (i <= nbpipes)
	{
		if (first == 0)
		{
			shell->execlist->fd_out = shell->general->pipes[0][1];
			first = 1;
		}
		else if (i == nbpipes)
			shell->execlist->fd_out = 1;
		else
			shell->execlist->fd_out = shell->general->pipes[i][1];
		i++;
		if (shell->execlist->next != NULL)
			shell->execlist = shell->execlist->next;
	}
}

void	ft_define_in_pipe(t_shell *shell, int nbpipes)
{
	int	i;
	int	first;

	first = 0;
	i = 0;
	while (i < nbpipes)
	{
		if (first == 0)
		{
			shell->execlist->fd_in = 0;
			first = 1;
		}
		else
		{
			shell->execlist->fd_in = shell->general->pipes[i][0];
			i++;
		}
		if (shell->execlist->next != NULL)
			shell->execlist = shell->execlist->next;
	}
}

int	ft_malloc_pipe(int nbpipes, int ***pipefd)
{
	int	i;

	i = 0;
	*pipefd = malloc(sizeof(int **) * nbpipes);
	if (!*pipefd)
		return (1);
	while (i < nbpipes)
	{
		(*pipefd)[i] = malloc(sizeof(int) * 2);
		if (!(*pipefd)[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_create_pipe(int nbpipe, t_shell *shell)
{
	int	i;

	i = 0;
	if (ft_malloc_pipe(nbpipe, &(shell->general->pipes)))
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
	if (i == 0)
		return (0);
	if (ft_create_pipe(shell->general->nbpipes, shell) == 1)
		return (1);
	ft_define_in_pipe(ft_h(shell), i);
	ft_define_out_pipe(ft_h(shell), i);
	return (0);
}
