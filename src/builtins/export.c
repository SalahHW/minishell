/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:23:30 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/09 09:20:38 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_print_for_export(char **tmp)
{
	int	i;
	int	j;

	j = 0;
	while (tmp[j])
	{
		i = 0;
		write(1, "declare -x ", 11);
		while (tmp[j][i])
		{
			if (tmp[j][i] == '=')
			{
				write(1, "=\"", 2);
			}
			else
			{
				write(1, &tmp[j][i], 1);
			}
			i++;
		}
		j++;
		write(1, "\"\n", 2);
	}
}

int	ft_export(t_exec *exec)
{
	int	i;

	i = 0;
	if (exec->execlist->arg[1] == NULL)
		ft_print_for_export(ft_ascii_sort(exec->general->expt));
	return (0);
	while (exec->execlist->arg[i])
	{
		if (ft_check_char_in_str(exec->execlist->arg[i], '='))
		{
			exec->general->expt = add_char_at_back_tab(exec->general->expt,
					exec->execlist->arg[i]);
			exec->general->env = add_char_at_back_tab(exec->general->env,
					exec->execlist->arg[i]);
		}
		else
			exec->general->expt = add_char_at_back_tab(exec->general->expt,
					exec->execlist->arg[i]);
		i++;
	}
	return (0);
}