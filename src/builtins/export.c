/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:23:30 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/03 15:15:49 by aherrman         ###   ########.fr       */
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

int	ft_export(t_shell *shell, char **arg)
{
	int	i;
	i = 0;
	ft_print_for_export(ft_ascii_sort(shell->expt));
	return (0);
	while (arg[i])
	{
		if (ft_check_char_in_str(arg[i], '='))
		{
			shell->expt = add_char_at_back_tab(shell->expt, arg[i]);
			shell->env = add_char_at_back_tab(shell->env, arg[i]);
		}
		else
			shell->expt = add_char_at_back_tab(shell->expt, arg[i]);
		i++;
	}
	return (0);
}
