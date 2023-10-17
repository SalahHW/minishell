/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:42:13 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/11 11:25:14 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	if (init_shell(&shell) == -1)
		return (EXIT_FAILURE);
	ft_create_env_and_path(&shell, envp);
	execute_cmd(&shell);
		// read_user_input(&shell);
	clean_shell(&shell);
}
