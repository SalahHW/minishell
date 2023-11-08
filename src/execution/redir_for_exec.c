/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_for_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:10:26 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 04:26:54 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_close_all_fd(t_shell *shell)
{
	while (shell->execlist)
	{
		if (shell->execlist->fd_in != 0)
			close(shell->execlist->fd_in);
		if (shell->execlist->fd_out != 1)
			close(shell->execlist->fd_out);
		if (shell->execlist->next != NULL)
			shell->execlist = shell->execlist->next;
	}
}

void	close_pipes(int nbpipes, int **pipefd, int j)
{
	int	i;

	(void)j;
	i = 0;
	if (nbpipes == 0)
		return ;
	while (i < nbpipes)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		i++;
	}
}

int	ft_def_redir_in(int fd_in)
{
	if (dup2(fd_in, STDIN_FILENO) == -1)
		return (1);
	return (0);
}

int	ft_def_redir_out(int fd_out)
{
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		return (1);
	return (0);
}

int	ft_def_redir(t_shell *shell, int i)
{
	if (ft_open_fd_in_out(shell->execlist, search_next_cmd(shell->tokens->head,
				i), shell) == 1)
	{
		shell->last_exit_code = 1;
		exit(1);
	}
	if (ft_def_redir_in(shell->execlist->fd_in) == 1)
		return (1);
	if (ft_def_redir_out(shell->execlist->fd_out) == 1)
		return (1);
	close_pipes(shell->general->nbpipes, shell->general->pipes, i);
	return (0);
}
