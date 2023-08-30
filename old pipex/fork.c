/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:46:45 by aherrman          #+#    #+#             */
/*   Updated: 2023/07/18 15:23:32 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	for_free(int *pids, int **pipefd, int nbpipes)
{
	int	i;

	i = 0;
	while (i < nbpipes)
	{
		free(pipefd[i]);
		i++;
	}
	if (pids)
		free(pids);
	free(pipefd);
}

int	*ft_m(int nbprocess, t_pipex *cmd)
{
	int	*pids;

	pids = malloc(sizeof(int) * nbprocess);
	if (!pids)
		ft_error("malloc failed", cmd);
	return (pids);
}

int	**ft_m2(int nbpipes, t_pipex *cmd)
{
	int	**pipefd;
	int	i;

	i = 0;
	pipefd = malloc(sizeof(int *) * nbpipes);
	if (!pipefd)
		ft_error("malloc failed", cmd);
	while (i < nbpipes)
	{
		pipefd[i] = malloc(sizeof(int) * 2);
		if (!pipefd[i])
			ft_error("malloc failed", cmd);
		i++;
	}
	return (pipefd);
}

void	ft_fork(t_pipex *cmd, int nbprocess, int nbpipe)
{
	int	*pids;
	int	**pipefd;
	int	i;
	int	nbpipes;

	i = 0;
	nbpipes = nbpipe;
	pids = ft_m(nbprocess, cmd);
	pipefd = ft_m2(nbpipes, cmd);
	ft_create_pipe(nbpipes, pipefd, cmd);
	while (i < nbprocess)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			ft_error("fork failed", cmd);
		else if (pids[i] == 0)
			if (ft_child_process(cmd, pipefd, i) == -1)
				ft_error("child process failed", cmd);
		if (cmd->lst->next != NULL)
			cmd->lst = cmd->lst->next;
		i++;
	}
	ft_parent_process(cmd, nbpipes, pipefd, nbprocess);
	for_free(pids, pipefd, nbpipes);
}
