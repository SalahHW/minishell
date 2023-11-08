/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:40:53 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 13:45:03 by sbouheni         ###   ########.fr       */
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
}						t_tokentype;

typedef struct s_token
{
	t_tokentype			type;
	char				*value;
	char				*cmd_path;
	char				**arg;
	int					fd;
	int					fd_in;
	int					fd_out;
	int					quote;
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
char					*get_next_token(char **input);
char					*extract_tokens(char *token_start, char *token_end);

char					*tokenize_operator(char **input);

int						count_tokens(char *input);

void					detect_tokens_type(t_token *token);

t_tokenlist				*init_tokens_list(void);
void					add_new_token(t_tokenlist *token, char *value);
void					replace_token(t_token *token, char *value);
void					clear_tokens_list(t_tokenlist *tokens);

char					*remove_quotes(char *str);
char					*skip_quotes(char *input);

char					*expand_variables(t_shell *shell, char *str);
char					*extract_var_name(char *str);

int						analyze_tokens(t_tokenlist *tokens_list);

#endif
