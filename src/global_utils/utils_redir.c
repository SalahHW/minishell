/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:37:22 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/10 10:36:14 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	redir_input(int input_fd)
{
	if (dup2(input_fd, STDIN_FILENO) == -1)
		return (1);
	return (0);
}

int	redir_output(int output_fd)
{
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		return (1);
	return (0);
}

int	ft_close_all_fd(t_token *token)
{
	while (token->next)
	{
		if (token->type == t_file)
			close(token->fd);
	}
	return (0);
}