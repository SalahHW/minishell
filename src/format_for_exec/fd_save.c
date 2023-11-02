/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:15:58 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/02 15:15:59 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_save_fd(t_shell *shell)
{
	shell->general->fd_in = dup(STDIN_FILENO);
	shell->general->fd_out = dup(STDOUT_FILENO);
}
