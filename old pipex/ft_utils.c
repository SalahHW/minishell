/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:43:58 by aherrman          #+#    #+#             */
/*   Updated: 2023/07/19 11:44:14 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_create_pipe(int nbpipe, int **pipes, t_pipex *cmd)
{
	int	i;

	i = 0;
	while (i < nbpipe)
	{
		if (pipe(pipes[i]) == -1)
		{
			ft_error("pipe failed", cmd);
		}
		i++;
	}
}

void	redir_input(int input_fd, t_pipex *cmd)
{
	if (dup2(input_fd, STDIN_FILENO) == -1)
		ft_error("dup2 for input failed", cmd);
}

void	redir_output(int output_fd, t_pipex *cmd)
{
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		ft_error("dup2  for output failed", cmd);
}

void	close_pipes(int nbpipes, int **pipefd, int j)
{
	int	i;

	i = 0;
	while (i <= nbpipes)
	{
		if (i != j || i == 0)
			close(pipefd[i][0]);
		if (i != j + 1)
			close(pipefd[i][1]);
		i++;
	}
}

void	close_mpipes(int nbpipes, int **pipefd, int nbprocess)
{
	int	i;

	i = 0;
	(void)nbprocess;
	while (i < nbpipes)
	{
		close(pipefd[i][0]);
		close(pipefd[i][1]);
		i++;
	}
}
