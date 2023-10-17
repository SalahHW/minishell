/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:46:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/17 16:27:59 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int unset(t_shell *exec)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (exec->execlist->arg[i])
	{
        j = 0;
		while (exec->general->env[j])
		{
			if (ft_strncmp(exec->execlist->arg[i], exec->general->env[j], ft_strlen(exec->execlist->arg[i])) == 0)
				exec->general->env = ft_delete_elem_in_tab(exec->execlist->arg[i], exec->general->env);
			j++;
		}
		i++;
	}
	return (0);
}