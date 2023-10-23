/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 08:26:16 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/17 16:49:23 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_child_process(char *cmd, char **arg, char **path)
{
	char	*tmp;

	tmp = ft_path(path, arg);
	if (tmp == NULL)
		return (1);
	if (execve(tmp, arg, env) == -1)
	{
		free(tmp);
		return (1);
		// error execve
	}
	free(tmp);
	return (0);
}

int	execve_main(t_exec *exec)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
		return (1);
	// fail fork
	else if (pid == 0)
		if (ft_child_process(exec->execlist->cmd_path, exec->execlist->arg,
				exec->general->path) == 1)
			return (1);
	// error execve
	waitpid(pid, &status, 0);
	return (0);
}
