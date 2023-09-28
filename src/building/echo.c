/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:56:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/28 08:52:48 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	echo(char **arg)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (arg[1] && ft_strncmp(arg[1], "-n", 2) == 0)
		n = 1;
	if (n == 1 && arg[2])
		printf("%s", ft_tab_on_one_line(arg + 2));
	else if (n == 0 && arg[2])
		printf("%s\n", ft_tab_on_one_line(arg + 2));
	else if (arg[2] == NULL)
	{
		if (n == 1)
			return (0);
		// new line
		else
			printf("\n");
	}
	return (0);
}
