/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:10:35 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/08 02:37:17 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	cd_argc_error(void)
{
	int	exit_code;

	exit_code = 1;
	ft_putstr_fd("cd: too many arguments\n", STDIN_FILENO);
	return (exit_code);
}

int	ft_cd(t_shell *exec)
{
	int		argc;
	int		exit_code;
	char	*home;

	exit_code = 0;
	home = get_var_value(exec->environement_list, "HOME");
	argc = ft_tab_size(exec->execlist->arg);
	if (argc > 2)
		return (cd_argc_error());
	if (!home && exec->execlist->arg[1] == NULL)
	{
		error("cd", NULL, 3);
		return (1);
	}
	else if (exec->execlist->arg[1] == NULL)
		exit_code = chdir(home);
	else
		exit_code = chdir(exec->execlist->arg[1]);
	if (exit_code != 0)
		return (1);
	pwd_change(exec);
	return (0);
}
