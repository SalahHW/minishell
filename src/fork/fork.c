/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:40:51 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/30 10:52:39 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// int	path_for_execve(t_shell *shell)
// {
// 	int		i;
// 	char	*path;
// 	char	*tmp;

// 	i = 0;
// 	while (shell->general->path[i])
// 	{
// 		path = ft_strdup(shell->general->path[i]);
// 		tmp = ft_strjoin(path, shell->execlist->cmd_path);
// 		free(path);
// 		if (access(tmp, F_OK) == 0)
// 		{
// 			free(shell->execlist->cmd_path);
// 			shell->execlist->cmd_path = ft_strdup(tmp);
// 			free(tmp);
// 			return (0);
// 		}
// 		free(tmp);
// 		i++;
// 	}
// 	return (1);
// }

int	ft_solo_child(t_shell *shell)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		get_cmd_path(shell);
		// path_for_execve(shell);
		if (ft_def_redir(shell, 0) == 1)
			return (1);
		if (execve(shell->execlist->cmd_path, shell->execlist->arg,
				shell->general->env) == -1)
		{
			error(shell->execlist->arg[0], NULL, 127);
			exit(127);
		}
	}
	return (0);
}

int	ft_child_process(t_shell *shell, int i)
{
	if (ft_def_redir(shell, i) == 1)
		return (1);
	get_cmd_path(shell);
	if (execve(shell->execlist->cmd_path, shell->execlist->arg,
			shell->general->env) == -1)
	{
		error(shell->execlist->arg[0], NULL, 127);
		exit(127);
	}
	return (0);
}

void	ft_parent_process(t_shell *shell, int nbprocess)
{
	int	i;
	int	status;

	i = 0;
	while (i < shell->general->nbpipes)
	{
		close(shell->general->pipes[i][0]);
		close(shell->general->pipes[i][1]);
		i++;
	}
	i = 0;
	while (i < nbprocess)
	{
		waitpid(-1, &status, 0);
		shell->last_exit_code = status % 255;
		i++;
	}
}
