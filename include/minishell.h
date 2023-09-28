/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:22:34 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/28 11:50:44 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//***** LIB *****//
# include "command.h"
# include "lexer.h"
# include "libft/libft.h"
# include "parser.h"
# include "signal.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// alex//
# include "global_utils.h"
# include "new.h"

extern volatile sig_atomic_t	g_sigquit_received;

//*****STRUCT*****//
typedef struct s_shell
{
	char						*prompt;
	char						*user_input;
	t_tokenlist					*tokens;
	int							status;
}								t_shell;

int								init_shell(t_shell *shell);
void							clean_shell(t_shell *shell);
void							read_user_input(t_shell *shell);
#endif
