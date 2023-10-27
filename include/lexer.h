/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:40:53 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/27 02:45:50 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef struct s_shell	t_shell;

typedef enum e_tokentype
{
	t_undifined,
	t_cmd,
	t_arg,
	t_pipe,
	t_redirect_in,
	t_redirect_out,
	t_redirect_append,
	t_heredoc,
	t_file,
	t_exit_status,
}						t_tokentype;

typedef enum e_quotetype
{
	none,
	single_quote,
	double_quote,
}						t_quotetype;

typedef struct s_token
{
	t_tokentype			type;
	t_quotetype			quote;
	char				*value;
	int					is_valid;
	char				*cmd_path;
	char				**arg;
	int					fd;
	int					fd_in;
	int					fd_out;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

typedef struct s_tokenlist
{
	t_token				*head;
	t_token				*tail;
}						t_tokenlist;

void					tokenizer(char *input, t_shell *shell);
t_tokenlist				*tokenize_input(char *input, t_shell *shell);
char					*extract_tokens(char *token_start, char *token_end);

char					*tokenize_word(char *input, t_tokenlist *tokens);

char					*tokenize_quote(char *input, t_tokenlist *tokens);

char					*tokenize_operator(char *input, t_tokenlist *tokens);

int						count_tokens(char *input);

void					detect_tokens_type(t_token *token);

t_tokenlist				*init_tokens_list(void);
void					add_new_token(t_tokenlist *token, char *value);
void					replace_token(t_token *token, char *value);
void					clear_tokens_list(t_tokenlist *tokens);

void					remove_quotes(t_token *token);

char					*expand_variables(t_shell *shell, char *str);

#endif
