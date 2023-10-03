/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:22:34 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/03 15:44:12 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//***** LIB *****//
//# include "command.h"
# include "global_utils.h"
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
# include <sys/wait.h>
# include <unistd.h>

extern volatile sig_atomic_t	g_sigquit_received;

//*****STRUCT*****//
typedef struct s_shell
{
	char						*prompt;
	char						*user_input;
	t_tokenlist					*tokens;
	int							status;
	char						**env;
	char						**path;
	char						**expt;
	char						*home;
	int							nbpipe;
	int							nbprocess;
	int							*pipefd;
}								t_shell;

int								init_shell(t_shell *shell);
void							clean_shell(t_shell *shell);
void							read_user_input(t_shell *shell);
int								execute_cmd(t_shell *shell);
// create env,path,home
void							ft_create_env_and_path(t_shell *shell,
									char **env);
// a mettre dans command.h//
int								ft_cd(char *arg, char **envp, char *home);
int								pwd(void);
int								pwd_change(t_shell *shell);
int								unset(t_shell *shell, char **arg);
int								ft_export(t_shell *shell, char **arg);
int								env(char **env);
#endif
