/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:31:31 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/08 13:47:42 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Print the tokens list
void	print_tokens_list(t_tokenlist *tokens)
{
	t_token	*token_ptr;

	token_ptr = tokens->head;
	while (token_ptr)
	{
		printf("Token: %s\n", token_ptr->value);
		if (token_ptr->type == t_undifined)
			printf("Type: undifined\n");
		else if (token_ptr->type == t_cmd)
			printf("Type: command\n");
		else if (token_ptr->type == t_arg)
			printf("Type: argument\n");
		else if (token_ptr->type == t_pipe)
			printf("Type: pipe\n");
		else if (token_ptr->type == t_redirect_in)
			printf("Type: redirect in\n");
		else if (token_ptr->type == t_redirect_out)
			printf("Type: redirect out\n");
		else if (token_ptr->type == t_redirect_append)
			printf("Type: redirect append\n");
		else if (token_ptr->type == t_heredoc)
			printf("Type: heredoc\n");
		else if (token_ptr->type == t_file)
			printf("Type: file\n");
		token_ptr = token_ptr->next;
	}
}
