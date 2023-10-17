/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_for_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:10:26 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/16 08:28:54 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_def_redir_in(int fd_in)
{
	if (fd_in != -99)
	{
		if (dup2(fd_in, STDIN_FILENO) == -1)
			return (1);
	}
	return (0);
}

int	ft_def_redir_out(int fd_out)
{
    printf("fd out = %d\n", fd_out);
	if (fd_out != -99)
	{
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			return (1);
	}
	return (0);
}

int	ft_def_redir(t_execlist *list)
{
	if (ft_def_redir_in(list->fd_in) == 1)
		return (1);
	// error dup2 on in
	if (ft_def_redir_out(list->fd_out) == 1)
		return (1);
	// error dup2 on out
	return (0);
}
