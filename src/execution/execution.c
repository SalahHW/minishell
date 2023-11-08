/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:38:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 04:32:00 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

int	execute_cmd(t_shell *shell)
{
	int	nbprocess;

	format_for_exec(shell);
	nbprocess = ft_lst_len(shell->execlist);
	if (nbprocess == 1)
		ft_only_one_cmd(ft_h(shell));
	else if (nbprocess > 1)
		ft_multi_cmd(ft_h(shell), nbprocess);
	else
		ft_heredoc(shell);
	ft_h(shell);
	dup2(shell->general->fd_in, STDIN_FILENO);
	dup2(shell->general->fd_out, STDOUT_FILENO);
	ft_h(shell);
	ft_parent_process(shell, nbprocess);
	ft_h(shell);
	ft_free_exec(shell);
	return (0);
}
