/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_for_exec2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 08:00:06 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 04:33:20 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_here_heredoc(t_token *token, t_shell *shell)
{
	int		fd;
	char	*line;

	fd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = readline("> ");
		if (ft_strncmp(line, token->value, ft_strlen(line)) == 0)
		{
			free(line);
			break ;
		}
		line = expand_heredoc_variables(shell, line);
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	token->fd = open(".tmp", O_RDONLY);
	if (token->fd < 0)
		return (1);
	return (0);
}

int	ft_token_input(t_token *token, t_tokentype type, t_execlist *execlist,
		t_shell *shell)
{
	if (type == t_redirect_in)
		token->fd = open(token->value, O_RDONLY, __O_DIRECTORY);
	if (token->fd == -1)
	{
		token->fd = open(token->value, O_RDONLY);
		if (token->fd < 0)
		{
			error(token->value, NULL, errno);
			return (1);
		}
	}
	if (type == t_heredoc)
	{
		if (ft_here_heredoc(token, shell) == 1)
			error(token->value, NULL, errno);
		return (1);
	}
	if (execlist->fd_in != 0)
		close(execlist->fd_in);
	execlist->fd_in = token->fd;
	return (0);
}

int	ft_token_output(t_token *token, t_tokentype type, t_execlist *execlist)
{
	if (type == t_redirect_out)
		token->fd = open(token->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (token->fd < 0)
		return (1);
	else if (type == t_redirect_append)
	{
		token->fd = open(token->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (token->fd < 0)
			return (1);
	}
	if (execlist->fd_out != 1)
		close(execlist->fd_out);
	execlist->fd_out = token->fd;
	return (0);
}

t_token	*search_next_cmd(t_token *token, int i)
{
	int	j;

	j = 0;
	while (token)
	{
		if (token->type == t_pipe)
			j++;
		if (j == i)
		{
			token = token->next;
			return (token);
		}
		token = token->next;
	}
	return (NULL);
}

int	ft_open_fd_in_out(t_execlist *execlist, t_token *token, t_shell *shell)
{
	while (token && token->type != t_pipe)
	{
		token->fd = 0;
		if (token->type == t_file)
		{
			if (token->prev && (token->prev->type == t_redirect_in
					|| token->prev->type == t_heredoc))
			{
				if (ft_token_input(token, token->prev->type, execlist,
						shell) == 1)
					return (1);
			}
			else if (token->prev && (token->prev->type == t_redirect_out
					|| token->prev->type == t_redirect_append))
			{
				if (ft_token_output(token, token->prev->type, execlist) == 1)
					return (1);
			}
		}
		token = token->next;
	}
	return (0);
}
