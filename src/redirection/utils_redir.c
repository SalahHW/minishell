/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:37:22 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/03 13:38:21 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	redir_input(int input_fd)
{
	if (dup2(input_fd, STDIN_FILENO) == -1)
		return(1);
}

void	redir_output(int output_fd)
{
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		return(1);
}