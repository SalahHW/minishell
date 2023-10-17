/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:22:34 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/17 17:19:42 by aherrman         ###   ########.fr       */
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
typedef struct s_execlist
{
	char						*cmd_path;
	char **arg; // arg[0]=cmd arg[1]=
				//-option(echo ou pour execve verifier dans lexec) arg[i]= un arguments//
	int							fd_in;
	int							fd_out;
	struct s_execlist			*next;
	struct s_execlist			*prev;
}								t_execlist;

typedef struct s_general
{
	int							status;
	char						**env;
	char						**path;
	char						**expt;
	char						*home;
	int							nbpipes;
	int							**pipes;
}								t_general;
typedef struct s_shell
{
	char						*prompt;
	char						*user_input;
	t_tokenlist					*tokens;
	t_general					*general;
	t_execlist					*execlist;
}								t_shell;

int								init_shell(t_shell *shell);
void							clean_shell(t_shell *shell);
void							read_user_input(t_shell *shell);
int								execute_cmd(t_shell *shell);
// create env,path,home//
void							ft_create_env_and_path(t_shell *shell,
									char **env);
// FORMAT//
// fornat for exec//
int								format_for_exec(t_shell *shell);
// PIPE//
// pipe//
int								ft_general_pipe(t_shell *shell);
int								redir_pipes(t_shell *shell);
// redirect//
int								ft_redirections(t_shell *shell);
int								ft_close_all_fd(t_token *token);
// utils redirection//
int								ft_close_all_fd(t_token *token);
int								redir_output(int output_fd);
int								redir_input(int input_fd);

// utils new struct//
void							ft_execadd_back(t_shell *shell,
									t_execlist *new);
t_execlist						*ft_new_execlist_node(t_token *token);
int								ft_lst_len(t_execlist *cmd);
void							free_execlist(t_execlist *execlist);
t_execlist						*ft_h(t_execlist *list);

// a mettre//
int								ft_cd(t_shell *exec);
int								pwd(void);
int								pwd_change(t_shell *exec);
int								unset(t_shell *exec);
int								ft_export(t_shell *exec);
int								env(char **env);
int								ft_echo(t_shell *exec);
// fortest//
void							ft_print_token_list(t_token *token);
// redir in exec//
int								ft_def_redir(t_execlist *list);
#endif
