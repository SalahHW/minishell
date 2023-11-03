/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:22:34 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/03 13:22:57 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//***** LIB *****//
//# include "command.h"
# include "environement.h"
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
	char						**arg;
	int							fd_in;
	int							fd_out;
	struct s_execlist			*next;
	struct s_execlist			*prev;
}								t_execlist;

typedef struct s_general
{
	int							status;
	char						**env;
	int							nbpipes;
	int							**pipes;
	int							*pids;
	int							fd_in;
	int							fd_out;
}								t_general;

typedef struct s_shell
{
	t_envlist					*environement_list;
	t_envlist					*export_list;
	char						*prompt;
	char						*user_input;
	t_tokenlist					*tokens;
	t_general					*general;
	t_execlist					*execlist;
	int							exit_code;
	int							last_exit_code;
}								t_shell;

int								init_shell(t_shell *shell);
void							clean_shell(t_shell *shell);
void							read_user_input(t_shell *shell);
int								execute_cmd(t_shell *shell);
void							get_cmd_path(t_shell *shell);
// FORMAT//
// fornat for exec//
int								format_for_exec(t_shell *shell);
// PIPE//
// pipe//
int								ft_general_pipe(t_shell *shell);
int								redir_pipes(t_shell *shell);
// redirect//
int								ft_redirections(t_shell *shell);
// utils new struct//
void							ft_execadd_back(t_shell *shell,
									t_execlist *new);
t_execlist						*ft_new_execlist_node(t_token *token);
int								ft_lst_len(t_execlist *cmd);
t_shell							*ft_h(t_shell *shell);
// exec_free//
void							ft_free_exec(t_shell *shell);

// buitins//
int								ft_cd(t_shell *exec);
int								pwd(void);
int								pwd_change(t_shell *exec);
int								unset(t_shell *exec);
int								ft_export(t_shell *exec);
int								env(t_shell *shell);
int								ft_echo(t_shell *exec);
// UTILSBUILTINS//
// UTILSBUILTINS//

int								check_if_egal(char *str);
void							ft_add_list(t_envlist *list, char *str);
// redir in exec//
int								ft_def_redir(t_shell *shell, int i);
void							ft_close_all_fd(t_shell *shell);
// redir in exec2//
t_token							*search_next_cmd(t_token *token, int i);
int								ft_open_fd_in_out(t_execlist *execlist,
									t_token *token, t_shell *shell);
int								ft_here_heredoc(t_token *token, t_shell *shell);
void							ft_heredoc(t_shell *shell);
// fork.c
int								ft_solo_child(t_shell *shell);
int								ft_child_process(t_shell *shell, int i);
void							ft_parent_process(t_shell *shell,
									int nbprocess);
// ERROR//
int								error(char *cmd, char *input, int error);

// fortest//
void							print_tokens_list(t_tokenlist *token);
void							print_execlist(t_execlist *list);

void							ft_save_fd(t_shell *shell);
char							*expand_heredoc_variables(t_shell *shell,
									char *str);

#endif
