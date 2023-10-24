/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_for_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:10:26 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/24 17:11:03 by aherrman         ###   ########.fr       */
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
		if (i != 0)
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
		if (i != 0)
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

void	ft_define_pipe(t_execlist *list, t_general *general, int i)
{
	if (general->nbpipes == 0)
		return ;
	if (i == 0)
	{
		list->fd_in = 0;
		list->fd_out = general->pipes[i][1];
	}
	else if (i != general->nbpipes)
	{
		list->fd_in = general->pipes[i][0];
		list->fd_out = general->pipes[i + 1][1];
	}
	else if (i == general->nbpipes)
	{
		list->fd_in = general->pipes[i][0];
		list->fd_out = 1;
	}
}

int	ft_def_redir(t_shell *shell, int i)
{
	fprintf(stderr, "\n\n je suis le fork n %d\n\n", i);
	ft_define_pipe(shell->execlist, shell->general, i);
	ft_open_fd_in_out(shell->execlist, search_next_cmd(shell->tokens->head, i));
	fprintf(stderr, "dans le fork OMG fd_in = %d fd_out = %d pipenb = %d\n",
		shell->execlist->fd_in, shell->execlist->fd_out,
		shell->general->nbpipes);
	if (ft_def_redir_in(shell->execlist->fd_in, shell->general->pipes, i) == 1)
		return (1);
	// error dup2 on in
	if (ft_def_redir_out(shell->execlist->fd_out, shell->general->pipes, i,
			shell->general->nbpipes) == 1)
		return (1);
	// error dup2 on out
	close_pipes(shell->general->nbpipes, shell->general->pipes, i);
	return (0);
}