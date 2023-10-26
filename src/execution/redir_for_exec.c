/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_for_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:10:26 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/26 06:43:17 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_pipes(int nbpipes, int **pipefd, int j)
{
	int	i;

	i = 0;
	if (nbpipes == 0)
		return ;
	while (i <= nbpipes)
	{
		if (i != j || i == 0)
			close(pipefd[i][0]);
		if (i != j + 1)
			close(pipefd[i][1]);
		i++;
	}
}

int	ft_def_redir_in(int fd_in, int **pipes, int i)
{
	if (fd_in != 0)
	{
		close(pipes[i][0]);
		if (dup2(fd_in, STDIN_FILENO) == -1)
			return (1);
	}
	else if (i != 0)
	{
		if (dup2(pipes[i][0], STDIN_FILENO) == -1)
			return (1);
	}
	return (0);
}

int	ft_def_redir_out(int fd_out, int **pipes, int i, int nbpipe)
{
	if (fd_out != 1)
	{
		close(pipes[i + 1][0]);
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			return (1);
	}
	else if (i > nbpipe)
	{
		if (dup2(pipes[i + 1][0], STDOUT_FILENO) == -1)
			return (1);
	}
	return (0);
}

int	ft_def_redir(t_execlist *list, int i, t_general *general)
{
	if (ft_def_redir_in(list->fd_in, general->pipes, i) == 1)
		return (1);
	if (ft_def_redir_out(list->fd_out, general->pipes, i,
			general->nbpipes) == 1)
		return (1);
	close_pipes(general->nbpipes, general->pipes, i);
	return (0);
}
