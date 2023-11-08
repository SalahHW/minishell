/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:29:54 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 04:42:51 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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

static void	handle_quote(char c, int *single_quoted, int *double_quoted)
{
	if (is_single_quote(c) && !*single_quoted && !*double_quoted)
		*single_quoted = 1;
	else if (is_single_quote(c) && *single_quoted && !*double_quoted)
		*single_quoted = 0;
	if (is_double_quote(c) && !*double_quoted && !*single_quoted)
		*double_quoted = 1;
	else if (is_double_quote(c) && *double_quoted && !*single_quoted)
		*double_quoted = 0;
}

char	*expand_variables(t_shell *shell, char *str)
{
	char	*str_ptr;
	char	*expanded_str;
	char	*dst_ptr;
	int		single_quoted;
	int		double_quoted;

	single_quoted = 0;
	double_quoted = 0;
	str_ptr = str;
	expanded_str = malloc(get_expanded_len(shell, str) + 1);
	dst_ptr = expanded_str;
	if (!expanded_str)
		return (NULL);
	while (*str_ptr)
	{
		if (is_quote(*str_ptr))
			handle_quote(*str_ptr, &single_quoted, &double_quoted);
		if (!single_quoted && (is_variable(str_ptr) || is_exit_status(str_ptr)))
			replace_variable(shell, &str_ptr, &dst_ptr);
		else
			*dst_ptr++ = *str_ptr++;
	}
	*dst_ptr = '\0';
	free(str);
	return (expanded_str);
}

char	*expand_heredoc_variables(t_shell *shell, char *str)
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
