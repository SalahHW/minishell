/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:10:35 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/06 11:22:32 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd(t_shell *exec)
{
	int		err;
	char	*home;

	err = 0;
	home = get_var_value(exec->environement_list, "HOME");
	if (home == NULL && exec->execlist->arg[1] == NULL)
	{
		error("cd", NULL, 3);
		return (1);
	}
	else if (exec->execlist->arg[1] == NULL)
		err = chdir(home);
	else
		err = chdir(exec->execlist->arg[1]);
	if (err != 0)
		return (1);
	// pwd_change(exec);
	return (0);
}
