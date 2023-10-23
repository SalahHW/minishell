/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:40:53 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/23 07:19:48 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_tokentype
{
	t_undifined,       // 0
	t_cmd,             // 1
	t_arg,             // 2
	t_pipe,            // 3
	t_redirect_in,     // 4
	t_redirect_out,    // 5
	t_redirect_append, // 6
	t_heredoc,         // 7
	t_file,            // 8
	t_exit_status,     // 9
}					t_tokentype;

typedef enum e_quotetype
{
	none,
	single_quote,
	double_quote,
}					t_quotetype;

typedef struct s_token
{
	t_tokentype		type;
	t_quotetype		quote;
	char			*value;
	int				is_valid;
	char			*cmd_path;
	char			**arg;
	// fd for file
	int				fd;
	// only for t_cmd//
	int				fd_in;
	int				fd_out;
	// cmd//
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_tokenlist
{
	t_token			*head;
	t_token			*tail;
}					t_tokenlist;

t_tokenlist			*tokenizer(char *input, char **env);
t_tokenlist			*tokenize_input(char *input, t_tokenlist *tokens);
char				*extract_tokens(char *token_start, char *token_end);

char				*tokenize_word(char *input, t_tokenlist *tokens);

char				*tokenize_quote(char *input, t_tokenlist *tokens);

char				*tokenize_operator(char *input, t_tokenlist *tokens);

int					count_tokens(char *input);

void				detect_tokens_type(t_tokenlist *tokens, char **env);

t_tokenlist			*init_tokens_list(void);
void				add_new_token(t_tokenlist *token, char *value);
void				replace_token(t_token *token, char *value);
void				clear_tokens_list(t_tokenlist *tokens);

void				remove_quotes(t_token *token);

char	*expand_variables(char *str, char **env);

#endif
