/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:42:13 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 02:48:14 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	int		exit_code;

	exit_code = 0;
	(void)argc;
	(void)argv;
	if (init_shell(&shell) == -1)
		return (EXIT_FAILURE);
	shell.environement_list = get_parent_environement(envp);
	read_user_input(&shell);
	exit_code = shell.last_exit_code;
	clean_shell(&shell);
	return (exit_code);
}
