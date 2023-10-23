/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:31:31 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/20 13:52:18 by aherrman         ###   ########.fr       */
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
		else if (token_ptr->type == t_heredoc)
			printf("Type: heredoc\n");
		else if (token_ptr->type == t_file)
			printf("Type: file\n");
		printf("Quote : %d\n", token_ptr->quote);
		token_ptr = token_ptr->next;
	}
}

void print_execlist(t_execlist *list)
{
	int i = 0;
	while(list)
	{
		printf("list element nbr %d\n", i++);
		printf("cmd_path: %s\n", list->cmd_path);
		printf("fd_in: %d fd_out %d\n", list->fd_in, list->fd_out);
		ft_print_tab_for_test(list->arg);
		list = list->next;
	}
	printf("\nend of list\n");
}
