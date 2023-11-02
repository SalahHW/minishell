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

void	clean_shell(t_shell *shell)
{
	free(shell->prompt);
	free(shell->general);
	clear_environement_list(shell->environement_list);
	clear_environement_list(shell->export_list);
}
