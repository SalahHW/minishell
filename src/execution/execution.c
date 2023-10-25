/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:38:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/25 15:33:30 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_print_token_list(t_token *token)
{
	while (token)
	{
		printf("token->value = %s\n", token->value);
		printf("token->type = %d\n", token->type);
		printf(" fd in = %d fd out = %d\n", token->fd_in, token->fd_out);
		printf("fd value %d\n", token->fd);
		token = token->next;
	}
}

void	ft_print_execlist(t_execlist *execlist)
{
	while (execlist)
	{
		printf("cmd_path = %s\n", execlist->cmd_path);
		printf("fd in = %d fd out = %d\n", execlist->fd_in, execlist->fd_out);
		ft_print_tab_for_test(execlist->arg);
		execlist = execlist->next;
	}
}

int	ft_for_builtins(char *str)
{
	char	*builtins_cmd[8];
	int		i;

	builtins_cmd[0] = "echo";
	builtins_cmd[1] = "cd";
	builtins_cmd[2] = "pwd";
	builtins_cmd[3] = "export";
	builtins_cmd[4] = "unset";
	builtins_cmd[5] = "env";
	builtins_cmd[6] = "exit";
	builtins_cmd[7] = 0;
	i = 0;
	while (builtins_cmd[i])
	{
		if (ft_strncmp(str, builtins_cmd[i], ft_strlen(builtins_cmd[i])) == 0
			&& ft_strlen(str) == ft_strlen(builtins_cmd[i]))
			return (1);
		i++;
	}
	return (0);
}

int	exec_builtins(t_shell *exec, int i)
{
	if (ft_def_redir(exec, i) == 1)
		return (1);
	if (ft_strncmp(exec->execlist->arg[0], "echo", 5) == 0)
		ft_echo(exec);
	else if (ft_strncmp(exec->execlist->arg[0], "env", 4) == 0)
		env(exec->general->env);
	else if (ft_strncmp(exec->execlist->arg[0], "cd", 3) == 0)
		ft_cd(exec);
	else if (ft_strncmp(exec->execlist->arg[0], "pwd", 4) == 0)
		pwd();
	else if (ft_strncmp(exec->execlist->arg[0], "unset", 6) == 0)
		unset(exec);
	else if (ft_strncmp(exec->execlist->arg[0], "export", 7) == 0)
		ft_export(exec);
	else if (ft_strncmp(exec->execlist->arg[0], "exit", 5) == 0)
		exec->general->status = 0;
	return (0);
}

int	ft_only_one_cmd(t_shell *shell)
{
	int	statut;

	if (ft_for_builtins(shell->execlist->arg[0]) == 1)
		exec_builtins(shell, 0);
	else
	{
		if (ft_solo_child(shell) == 1)
			return (1);
		// ERR solochild
		waitpid(-1, &statut, 0);
	}
	return (0);
}

int	ft_multi_cmd(t_shell *shell, int nbprocess)
{
	int	i;

	i = 0;
	while (i < nbprocess)
	{
		shell->general->pids[i] = fork();
		if (shell->general->pids[i] == -1)
			return (1);
		else if (shell->general->pids[i] == 0)
		{
			if (ft_for_builtins(shell->execlist->arg[0]) == 1)
				exec_builtins(shell, i);
			// ERROR FORK//
			else if (ft_child_process(shell, i) == 1)
				return (1);
			// error on child
		}
		if (shell->execlist->next)
			shell->execlist = shell->execlist->next;
		i++;
	}
	ft_parent_process(shell, nbprocess);
	return (0);
}

int	execute_cmd(t_shell *shell)
{
	int	nbprocess;

	format_for_exec(shell);
	nbprocess = ft_lst_len(shell->execlist);
	if (nbprocess == 1)
	{
		if (ft_only_one_cmd(ft_h(shell)) == 1)
			return (1);
	}
	else if (nbprocess > 1)
	{
		if (ft_multi_cmd(ft_h(shell), nbprocess) == 1)
			return (1);
	}
	ft_h(shell);
	dup2(shell->general->fd_in, STDIN_FILENO);
	dup2(shell->general->fd_out, STDOUT_FILENO);
	printf("nbprocess = %d nbpipes  = %d \n", nbprocess,shell->general->nbpipes);
	//print_execlist(shell->execlist);
	ft_h(shell);
	ft_free_exec(shell);
	return (0);
}
