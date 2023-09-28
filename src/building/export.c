/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:23:30 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/28 11:03:51 by aherrman         ###   ########.fr       */
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
	write(1, "\n", 1);
}

int	export(t_mini *mini, char **arg)
{
	int	i;

	i = 0;
	if (arg[1] == NULL)
		ft_print_export(ft_ascii_sort(mini->expt));
	else
	{
		while (arg[i])
		{
			if (ft_check_char_at_back_tab(arg[i], "="))
			{
				mini->expt = add_char_at_back_tab(arg[i], mini->expt);
				mini->env = fadd_char_at_back_tab(arg[i], mini->env);
			}
			else
				mini->expt = add_char_at_back_tab(arg[i], mini->expt);
			i++;
		}
	}
}
