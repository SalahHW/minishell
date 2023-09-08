/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:53:54 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/08 00:09:33 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void read_user_input(t_shell *shell)
{
	char *line;

	line = NULL;
	while (!line)
		line = readline(shell->prompt);
	shell->user_input = line;
}
