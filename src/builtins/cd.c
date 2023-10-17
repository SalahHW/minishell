/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:10:35 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/17 16:26:50 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd(t_shell *exec)
{
	int	err;

	err = 0;
	if (exec->execlist->arg == NULL && ft_search_in_tab(exec->general->env, "HOME") != NULL)
		return (1);
	else if (exec->execlist->arg == NULL)
		err = chdir(exec->general->home);
	else
		err = chdir(exec->execlist->arg[1]);
	if (err != 0)
		return (1);
	return (0);
}
