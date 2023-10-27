/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement_extraction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:57:43 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/24 18:08:37 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*extract_varname(char *str)
{
	char	*varname;
	int		i;

	i = 0;
	while (str[i] != '=')
		i++;
	varname = ft_substr(str, 0, i);
	return (varname);
}

char	*extract_varvalue(char *str)
{
	char	*varvalue;

	while (*str != '=')
		str++;
	str++;
	varvalue = ft_strdup(str);
	return (varvalue);
}
