/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environement_extraction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:57:43 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/31 17:08:19 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*extract_varname(char *str)
{
	char	*varname;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	varname = ft_substr(str, 0, i);
	return (varname);
}

char	*extract_varvalue(char *str)
{
	char	*varvalue;

	while (*str && *str != '=')
		str++;
	str++;
	varvalue = ft_strdup(str);
	return (varvalue);
}
