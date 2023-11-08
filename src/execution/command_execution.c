/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 04:27:59 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 04:32:01 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_only_one_cmd(t_shell *shell)
{
	if (get_var_value(shell->environement_list, "PATH") != NULL
		|| (((ft_for_builtins(shell->execlist->arg[0]) == 1)
				&& ft_strncmp(shell->execlist->arg[0], "env", 3) != 0)
			|| (access(shell->execlist->arg[0], F_OK) == 0)))
	{
		if (ft_for_builtins(shell->execlist->arg[0]) == 1)
		{
			shell->general->b_err = exec_builtins(shell, 0);
		}
		else
		{
			if (ft_solo_child(shell) == 1)
				return (1);
		}
	}
	else
	{
		error(shell->execlist->arg[0], NULL, 1);
	}
	return (0);
}

int	ft_multi_cmd(t_shell *shell, int nbprocess)
{
	int	i;

	i = 0;
	signal_handlers(IGNORE);
	while (i < nbprocess)
	{
		shell->general->pids[i] = fork();
		if (shell->general->pids[i] == -1)
			return (1);
		else if (shell->general->pids[i] == 0)
		{
			signal_handlers(DEFAULT);
			ft_multi_cmd2(shell, i);
		}
		if (shell->execlist->next)
			shell->execlist = shell->execlist->next;
		i++;
	}
	return (0);
}

int	ft_multi_cmd2(t_shell *shell, int i)
{
	if (get_var_value(shell->environement_list, "PATH") != NULL
		|| (((ft_for_builtins(shell->execlist->arg[0]) == 1)
				&& ft_strncmp(shell->execlist->arg[0], "env", 3) != 0)
			|| (access(shell->execlist->arg[0], F_OK) == 0)))
	{
		if (ft_for_builtins(shell->execlist->arg[0]) == 1)
		{
			exec_builtins(shell, i);
			exit(0);
		}
		else
			ft_child_process(shell, i);
	}
	else
	{
		error(shell->execlist->arg[0], NULL, 1);
		exit(127);
	}
	return (0);
}

int	exec_builtins(t_shell *exec, int i)
{
	int	err;

	err = 0;
	if (ft_def_redir(exec, i) == 1)
		return (1);
	if (ft_strncmp(exec->execlist->arg[0], "echo", 5) == 0)
		err = ft_echo(exec);
	else if (ft_strncmp(exec->execlist->arg[0], "env", 4) == 0)
		err = env(exec);
	else if (ft_strncmp(exec->execlist->arg[0], "cd", 3) == 0)
		err = ft_cd(exec);
	else if (ft_strncmp(exec->execlist->arg[0], "pwd", 4) == 0)
		err = pwd();
	else if (ft_strncmp(exec->execlist->arg[0], "unset", 6) == 0)
		err = unset(exec);
	else if (ft_strncmp(exec->execlist->arg[0], "export", 7) == 0)
		err = ft_export(exec);
	else if (ft_strncmp(exec->execlist->arg[0], "exit", 5) == 0)
		err = minishell_exit(exec);
	return (err);
}
