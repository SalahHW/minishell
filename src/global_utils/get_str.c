/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 05:21:44 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/01 05:22:52 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Take a start and a end and make a string with char beetween
char	*get_str(char *start, char *end)
{
	char	*new_str;
	int		new_str_len;

	new_str_len = end - start + 1;
	new_str = malloc(sizeof(char) * new_str_len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, start, new_str_len);
	return (new_str);
}
