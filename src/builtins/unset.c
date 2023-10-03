/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:46:03 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/03 15:15:32 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int unset(t_shell *shell,char **arg)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (arg[i])
	{
        j = 0;
		while (shell->env[j])
		{
			if (ft_strncmp(arg[i], shell->env[j], ft_strlen(arg[i])) == 0)
				shell->env = ft_delete_elem_in_tab(arg[i], shell->env);
			j++;
		}
		i++;
	}
	return (0);
}