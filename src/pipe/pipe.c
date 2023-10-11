/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:36:12 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/10 11:03:10 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
		if (pipe(pipes[i]) == -1)
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
	token = shell->tokenlist->head;
	while (token)
	{
		if (token->type == t_pipe)
			i++;
		token = token->next;
	}
	shell->general->nbpipe = i;
	if (ft_create_pipe(shell->general->nbpipe, shell) == 1)
		return (1);
}
