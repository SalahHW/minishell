/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_varname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 04:41:39 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 04:43:07 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*extract_var_name(char *str)
{
	char	*var_name;
	char	*var_start;
	char	*var_end;

	var_start = str + 1;
	var_end = str + 1;
	while (*var_end && (ft_isalnum(*var_end) || *var_end == '_'))
		var_end++;
	var_name = ft_substr(var_start, 0, var_end - var_start);
	return (var_name);
}
