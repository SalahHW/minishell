/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:27:32 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/03 12:05:18 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_path(char **path, char **arg)
{
	int		i;
	char	*tmp;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path, arg[0]);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}
int	*ft_create_pids(int nbprocess)
{
	int	*pids;

	pids = malloc(sizeof(int) * nbprocess);
	if (!pids)
		return (NULL);
	return (pids);
}
int	**ft_create_pipefd(int nbpipes)
{
	int	**pipefd;
	int	i;

	i = 0;
	pipefd = malloc(sizeof(int *) * nbpipes);
	if (!pipefd)
		return (NULL);
	while (i < nbpipes)
	{
		pipefd[i] = malloc(sizeof(int) * 2);
		if (!pipefd[i])
			return (NULL);
		i++;
	}
	return (pipefd);
}
int	ft_create_pipe(int nbpipe, int **pipes)
{
	int i;

	i = 0;
	while (i < nbpipe)
	{
		if (pipe(pipes[i]) == -1)
			return (1);
		i++;
	}
}