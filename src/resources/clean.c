/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:42:05 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/28 17:28:36 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_for_general(t_shell *shell)
{
	free_tab(shell->general->env);
	free_tab(shell->general->path);
	free_tab(shell->general->expt);
	free(shell->general->home);
	free(shell->general);
}
void	clean_shell(t_shell *shell)
{
	free(shell->prompt);
	clear_environement_list(shell->environement_list);
}
