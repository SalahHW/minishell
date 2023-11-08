/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:54:44 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 03:16:23 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	exit_int_error(char *str)
{
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	return (2);
}

static int	exit_argc_error(t_shell *shell)
{
	int	exit_code;

	exit_code = 1;
	ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
	if (shell->last_exit_code != 0)
		exit_code = shell->last_exit_code;
	return (exit_code);
}

int	minishell_exit(t_shell *shell)
{
	int	argc;
	int	exit_code;

	exit_code = 0;
	argc = ft_tab_size(shell->execlist->arg);
	if (argc > 2)
		return (exit_argc_error(shell));
	if (argc == 2)
	{
		if (is_int_compatible(shell->execlist->arg[1]))
			exit_code = ft_atoi(shell->execlist->arg[1]);
		else
			exit_code = exit_int_error(shell->execlist->arg[1]);
		shell->general->status = 0;
	}
	printf("exit\n");
	if (exit_code > 255 || exit_code < 0)
		exit_code %= 256;
	if (exit_code < 0)
		exit_code += 256;
	shell->general->status = 0;
	return (exit_code);
}
