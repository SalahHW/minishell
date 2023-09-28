/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:46:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/27 16:35:32 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	unset(char **arg, t_mini *mini)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (arg[i])
	{
        j = 0;
		while (mini->env[j])
		{
			if (ft_strncmp(arg[i], mini->env[j], ft_strlen(arg[i])) == 0)
				mini->env = ft_delete_elem_in_tab(arg[i], mini->env);
			j++;
		}
		i++;
	}
	return (0);
}