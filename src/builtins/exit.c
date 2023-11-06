/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 01:54:44 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/06 12:07:34 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_a_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	minishell_exit(t_shell *shell)
{
	int	argc;
	int	exit_code;

	exit_code = 0;
	argc = ft_tab_size(shell->execlist->arg);
	if (argc > 2)
	{
		printf("exit\n");
		error(shell->execlist->arg[0], NULL, 4);
		if (shell->last_exit_code != 0)
			return (shell->last_exit_code);
		else
			return (1);
	}
	exit_code = ft_atoi(shell->execlist->arg[1]);
	printf("exit\n");
	if (is_a_number(shell->execlist->arg[1]) == 0)
		error(shell->execlist->arg[0], shell->execlist->arg[1], 5);
	if (exit_code > 255)
		exit_code %= 256;
	shell->general->status = 0;
	return (exit_code);
}
