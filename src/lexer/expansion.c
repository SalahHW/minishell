/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:29:54 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/18 09:24:07 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_variable(char *str)
{
	if (*str == '$' && (ft_isalnum(*(str + 1)) || *(str + 1) == '_'))
		return (1);
	return (0);
}

static char *get_var_name(char *str)
{
	char *var_name;
	char *var_start;
	char *var_end;

	if (!str || *str != '$')
		return (NULL);
	var_start = str + 1;
	var_end = str + 1;
	while (*var_end && (ft_isalnum(*var_end) || *var_end == '_'))
		var_end++;
	var_name = ft_substr(var_start, 0, var_end - var_start);
	return (var_name);
}

static int get_expanded_len(char *str, char **env)
{
	int len;
	char *var_name;
	char *var_value;
	char *str_ptr;

	len = 0;
	str_ptr = str;
	while (*str_ptr)
	{
		if (is_variable(str_ptr))
		{
			var_name = get_var_name(str_ptr);
			var_value = ft_search_var_in_env(env, var_name, 2);
			len += ft_strlen(var_value);
			str_ptr += ft_strlen(var_name) + 1;
			free(var_name);
		}
		else
		{
			len++;
			str_ptr++;
		}
	}
	return len;
}

char *expand_variables(char *str, char **env)
{
	char *str_ptr = str;
	char *expanded_str;
	char *var_name;
	char *var_value;
	int len;

	len = get_expanded_len(str, env);
	expanded_str = malloc(len + 1);
	if (!expanded_str)
		return NULL;

	char *dst_ptr = expanded_str;
	str_ptr = str;

	while (*str_ptr)
	{
		if (is_variable(str_ptr))
		{
			var_name = get_var_name(str_ptr);
			var_value = ft_search_var_in_env(env, var_name, 2);
			if (var_value)
			{
				ft_strlcpy(dst_ptr, var_value, ft_strlen(var_value) + 1);
				dst_ptr += ft_strlen(var_value);
			}
			str_ptr += ft_strlen(var_name) + 1;
			free(var_name);
		}
		else
		{
			*dst_ptr++ = *str_ptr++;
		}
	}
	*dst_ptr = '\0';
	free(str);
	return expanded_str;
}