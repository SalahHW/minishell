/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:40:53 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/22 04:55:17 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_tokentype
{
	token_undifined,
	token_cmd,
	token_arg,
	token_pipe,
	token_redirect_in,
	token_redirect_out,
	token_redirect_append,
}					t_tokentype;

typedef struct s_token
{
	t_tokentype		type;
	char			*value;
	struct s_token	*next;
}					t_token;

typedef struct s_tokenlist
{
	t_token			*head;
	t_token			*tail;
}					t_tokenlist;

t_tokenlist			*extract_tokens(char *input);
char				*get_next_token(char **input_ptr);
int					count_tokens(char *input);
void				free_tokens(t_tokenlist *tokens);

void				detect_tokens_type(t_tokenlist *tokens);

#endif
