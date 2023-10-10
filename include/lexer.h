/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:40:53 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/09 09:50:44 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

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
}					t_tokentype;

typedef struct s_token
{
	t_tokentype		type;
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

t_tokenlist			*extract_tokens(char *input);
char				*get_next_token(char **input_ptr);
int					count_tokens(char *input);

void				detect_tokens_type(t_tokenlist *tokens);

t_tokenlist			*init_tokens_list(void);
void				add_new_token(t_tokenlist *token, char *value);
void				clear_tokens_list(t_tokenlist *tokens);

#endif
