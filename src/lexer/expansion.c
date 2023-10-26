/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:29:54 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/26 06:53:25 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*extract_var_name(char *str)
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

static int	get_expanded_len(t_shell *shell, char *str)
{
	int		len;
	char	*var_name;
	char	*var_value;
	char	*str_ptr;

	len = 0;
	str_ptr = str;
	while (*str_ptr)
	{
		if (is_variable(str_ptr))
		{
			var_name = extract_var_name(str_ptr);
			var_value = get_var_value(shell->environement_list, var_name);
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
	return (len);
}

static void	replace_variable(t_shell *shell, char **str_ptr, char **dst_ptr)
{
	char	*var_name;
	char	*var_value;

	if (is_variable(*str_ptr))
	{
		var_name = extract_var_name(*str_ptr);
		var_value = get_var_value(shell->environement_list, var_name);
		if (var_value)
		{
			ft_strlcpy(*dst_ptr, var_value, ft_strlen(var_value) + 1);
			*dst_ptr += ft_strlen(var_value);
		}
		*str_ptr += ft_strlen(var_name) + 1;
		free(var_name);
	}
	else if (is_exit_status(*str_ptr))
	{
		var_value = ft_itoa(shell->last_exit_code);
		ft_strlcpy(*dst_ptr, var_value, ft_strlen(var_value) + 1);
		*dst_ptr += ft_strlen(var_value);
		*str_ptr += 2;
		free(var_value);
	}
}

char	*expand_variables(t_shell *shell, char *str)
{
	char	*str_ptr;
	char	*expanded_str;
	char	*dst_ptr;

	str_ptr = str;
	expanded_str = malloc(get_expanded_len(shell, str) + 1);
	dst_ptr = expanded_str;
	if (!expanded_str)
		return (NULL);
	while (*str_ptr)
	{
		if (is_variable(str_ptr) || is_exit_status(str_ptr))
			replace_variable(shell, &str_ptr, &dst_ptr);
		else
			*dst_ptr++ = *str_ptr++;
	}
	*dst_ptr = '\0';
	free(str);
	return (expanded_str);
}
