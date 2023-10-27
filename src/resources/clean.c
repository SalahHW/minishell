/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:42:05 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/27 02:57:58 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	clean_shell(t_shell *shell)
{
	free_for_general(shell);
	free(shell->prompt);
	free(shell->general);
	clear_environement_list(shell->environement_list);
}
