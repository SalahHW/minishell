/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:40:53 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/10 23:52:14 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_tokentype
{
	token_cmd,
	token_arg,
}				t_tokentype;

typedef struct s_token
{
	t_tokentype	type;
	char		*value;
}				t_token;

t_token			*extract_tokens(char *input);
char			*next_token(char *input, char **remaining);
int				count_tokens(char *input);
void			free_tokens(t_token *tokens);

#endif
