/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:36:12 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/03 11:59:44 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_create_pipe(int nbpipe, int **pipes)
{
	int	i;

	i = 0;
	while (i < nbpipe)
	{
		if (pipe(pipes[i]) == -1)
        return(1);
		i++;
	}
}