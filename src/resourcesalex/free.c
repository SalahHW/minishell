/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:33:02 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/27 15:25:54 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void mini_free(t_mini *mini)
{
	if (mini)
	{
		if (mini->env)
			free_tab(mini->env);
		if (mini->path)
			free_tab(mini->path);
		if(mini->expt)
			free_tab(mini->expt);
		if (mini->home)
			free(mini->home);
	}
	free(mini);
}