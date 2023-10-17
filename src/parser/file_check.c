/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:26:51 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/16 08:33:38 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_here_heredoc(t_token *token)
{
	int		fd;
	char	*line;

	fd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (1);
	while (1)
	{
		line = readline("> ");
		if (ft_strcmp(line, token->value) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	token->fd = open(".tmp", O_RDONLY);
	if (token->fd < 0)
		return (1);
	return (0);
}

int	ft_token_input(t_token *token, t_tokentype type)
{
	if (type == t_redirect_in)
		token->fd = open(token->value, O_RDONLY, __O_DIRECTORY);
	if (token->fd == -1)
	{
		token->fd = open(token->value, O_RDONLY);
		if (token->fd < 0)
		{
			// No such file or directory
			return (1);
		}
		else if (type == t_heredoc)
		{
			if (ft_here_heredoc(token) == 1)
				return (1);
			// heredocje sais pas atm
		}
	}
	return (0);
}
int	ft_token_output(t_token *token, t_tokentype type)
{
	if (type == t_redirect_out)
		token->fd = open(token->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (token->fd < 0)
	{
		// No fail creat file
		return (1);
	}
	else if (type == t_redirect_append)
	{
		token->fd = open(token->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (token->fd < 0)
		{
			// fail create file
			return (1);
		}
	}
	return (0);
}

int	ft_file_can_open(t_token *token)
{
	while (token)
	{
		printf("token->value = %s token type %d \n", token->value, token->type);
		if (token->type == t_file)
		{
			if (token->prev && (token->prev->type == t_redirect_in
					|| token->prev->type == t_heredoc))
			{
				if (ft_token_input(token, token->prev->type) == 1)
					return (1);
			}
			else if (token->prev && (token->prev->type == t_redirect_out
					|| token->prev->type == t_redirect_append))
			{
				if (ft_token_output(token, token->prev->type) == 1)
					return (1);
			}
		}
		if (token->next)
			token = token->next;
		else
			break ;
	}
	return (0);
}

int	check_file(t_tokenlist *tokens)
{
	if (ft_file_can_open(tokens->head) == 1)
	{
		ft_close_all_fd(tokens->head);
		return (1);
	}
	return (0);
}
