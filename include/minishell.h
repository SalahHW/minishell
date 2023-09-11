/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:22:34 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/11 02:51:53 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//***** LIB *****//
# include "lexer.h"
# include "libft/libft.h"
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

extern volatile sig_atomic_t	g_sigquit_received;

//*****STRUCT*****//
typedef struct s_shell
{
	char						*prompt;
	char						*user_input;
	t_token						*tokens;
	int							status;
}								t_shell;

typedef struct s_lint
{
	long int					t0;
	long int					t1;
	long int					t2;
	long int					t3;
	long int					t4;
	long int					t5;
}								t_lint;

typedef struct s_string
{
	char						*s0;
	char						*s1;
	char						*s2;
	char						*s3;
}								t_string;

typedef struct s_temp
{
	t_lint						i;
	t_string					s;

}								t_temp;
typedef struct s_lst
{
	char						*cmd;
	char						*vpath;
	struct s_lst				*next;
}								t_lst;

typedef struct s_mini
{
	char						**env;
	char						**expt;
	char						**path;
	t_lst						*lst;

}								t_mini;

void							ft_arg_to_mini(char **env, t_mini *mini);
int								init_shell(t_shell *shell);
void							clean_shell(t_shell *shell);
void							read_user_input(t_shell *shell);
#endif
