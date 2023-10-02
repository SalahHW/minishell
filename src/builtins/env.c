/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:09:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/02 09:35:20 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env(char **env)
{
	printf("env\n");
	int i;

	i = 0;
	if (!env)
		return (1);
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}