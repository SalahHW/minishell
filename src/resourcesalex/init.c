/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:32:32 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/27 15:26:00 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_init_mini(t_mini *mini)
{
	////general data///
	mini->env = NULL;
	mini->path = NULL;
	mini->expt = NULL;
	mini->home = NULL;
}
