/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:00:09 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/31 16:32:54 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_if_egal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_add_list(t_envlist *list, char *str)
{
	char		*varname;
	char		*varvalue;

	varname = extract_varname(str);
	varvalue = extract_varvalue(str);
	add_new_var(list, varname, varvalue);
}
