/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:54:44 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/06 02:18:23 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	minishell_exit(t_shell *shell)
{
	int	argc;
	int	exit_code;

	exit_code = 0;
	argc = ft_tab_size(shell->execlist->arg);
	if (argc > 2)
	{
		printf("exit\n");
		printf("exit: too many arguments\n");
		return (-1);
	}
	if (argc == 1)
	{
		exit_code = ft_atoi(shell->execlist->arg[1]);
		printf("exit\n");
		if (exit_code > 255)
			exit_code %= 256;
	}
	shell->general->status = 0;
	return (exit_code);
}
