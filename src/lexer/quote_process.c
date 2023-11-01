/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:24:46 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/01 20:51:54 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*join_char(char *str, char c)
{
	char	*new_str;
	char	*str_ptr;
	char	*new_str_ptr;

	if (!str || !c)
		return (NULL);
	new_str = malloc(ft_strlen(str) + 2);
	if (!new_str)
		return (NULL);
	new_str_ptr = new_str;
	str_ptr = str;
	while (*str_ptr)
		*new_str_ptr++ = *str_ptr++;
	*new_str_ptr++ = c;
	*new_str_ptr = '\0';
	free(str);
	str = NULL;
	return (new_str);
}

static char	*handle_quoted_content(char **str_ptr)
{
	char	*start;
	char	*content;

	start = *str_ptr + 1;
	*str_ptr = skip_quotes(*str_ptr);
	content = get_str(start, *str_ptr);
	(*str_ptr)++;
	return (content);
}

char	*remove_quotes(char *str)
{
	char	*str_ptr;
	char	*content;
	char	*old_value;
	char	*new_value;

	str_ptr = str;
	new_value = ft_strdup("");
	while (*str_ptr)
	{
		if (is_quote(*str_ptr))
		{
			content = handle_quoted_content(&str_ptr);
			old_value = new_value;
			new_value = ft_strjoin(new_value, content);
			free(old_value);
			free(content);
		}
		else
		{
			new_value = join_char(new_value, *str_ptr);
			str_ptr++;
		}
	}
	free(str);
	return (new_value);
}

char	*skip_quotes(char *input)
{
	char	quote;

	quote = *input;
	input++;
	while (*input && *input != quote)
		input++;
	if (!*input)
	{
		printf("Warning : Unclosed quote %c\nUndefined behaviour\n", quote);
		return (NULL);
	}
	return (input);
}
