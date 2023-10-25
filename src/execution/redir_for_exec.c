/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_for_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:10:26 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/25 16:02:22 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_close_all_fd(t_token *token)
{
	while (token && token->type != t_pipe)
	{
		if (token->type == t_file)
			if (close(token->fd) == 1)
				return (1);
		token = token->next;
	}
	return (0);
}

void	close_pipes(int nbpipes, int **pipefd, int j)
{
	int	i;

	i = 0;
	if (nbpipes == 0)
		return ;
	while (i < nbpipes)
	{
		if (i != j )
			close(pipefd[i][0]);
		if (i != j + 1)
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
	fprintf(stderr,"\n\n  ma cmd = %s je suis le fork n %d fd_in = %d fd_out =% d np pipe = %d\n\n ", shell->execlist->cmd_path, i,shell->execlist->fd_in,shell->execlist->fd_out,shell->general->nbpipes);
	ft_open_fd_in_out(shell->execlist, search_next_cmd(shell->tokens->head, i));
	if (ft_def_redir_in(shell->execlist->fd_in) == 1)
		return (1);
	// error dup2 on in
	if (ft_def_redir_out(shell->execlist->fd_out) == 1)
		return (1);
	// error dup2 on out
	close_pipes(shell->general->nbpipes, shell->general->pipes, i);
	return (0);
}