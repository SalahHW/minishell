/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:56:41 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/03 10:21:46 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	echo(t_token *token)
{
	int		i;
	int		n;
	t_token	*token_ptr;

	i = 0;
	n = 0;
	if (token_ptr && token_ptr->type == t_cmd && ft_strncmp(token_ptr->value,
			"-n", 3) == 0)
		n = 1;
	if (n == 1 && token_ptr->next->type == t_arg)
		printf("%s", ft_tab_on_one_line(token_ptr->next->value));
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
// PERROR a lire
