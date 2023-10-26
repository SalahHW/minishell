/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_variable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:17:38 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/25 17:20:04 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_variable(char *str)
{
	if (*str == '$' && (ft_isalnum(*(str + 1)) || *(str + 1) == '_'))
		return (1);
	return (0);
}
