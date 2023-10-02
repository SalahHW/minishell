/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:42:13 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/02 16:43:00 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int	ft_test(t_mini *mini)
// {
	// char *path;
	// char **arg;
	// int pid ;
	
	// path = ft_strdup("/bin/ls");
	// arg = malloc(sizeof(char *) * 3);
	// arg[0] = ft_strdup("ls");
	// arg[1] = ft_strdup("-l");
	// arg[2] = NULL;
	//  (void)mini;
	// char **tab;
	// char **str;
	// str = malloc(sizeof(char *) * 3);
	// str[0] = ft_strdup("hello");
	// str[1] = ft_strdup("blablaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	// tab = malloc(sizeof(char *) * 8);
	// str[2] = NULL;
	// tab[0] = ft_strdup("echo");
	// tab[1] = ft_strdup("hello");
	// tab[2] = ft_strdup("world");
	// tab[3] = ft_strdup("!");
	// tab[4] = ft_strdup("echo1");
	// tab[5] = ft_strdup("hello1");
	// tab[6] = ft_strdup("world1");
	// tab[7] = ft_strdup("!1");
	// tab[8] = NULL;
	// ft_print_tab_for_test(tab);
	// tab = ft_replace_in_tab(tab, str[0], str[1]);
	// tab = ft_replace_in_tab(tab, "!", "blabla");
	// tab = ft_delete_elem_in_tab("echo1", tab);
	// tab = ft_delete_elem_in_tab("echo", tab);
	// printf("\ntab after replace:\n");
	// ft_print_tab_for_test(tab);
		// pid = fork();
	// if (pid == -1)
	// 	return (-1);
	// else if (pid == 0)
	// 	if (execve(path, arg, NULL) == -1)
	// 		return (1);
	// printf("%s\n", getcwd(NULL, 0));
	// printf("BEFORE PWD = %s OLDPWD = %s\n", ft_search_var_in_env(mini->env,
	// 		"OLDPWD", 1), ft_search_var_in_env(mini->env, "OLDPWD", 1));
	// chdir("..");
	// pwd_change(mini);
	// printf("AFTER PWD = %s OLDPWD = %s\n", ft_search_var_in_env(mini->env,
	// 		"PWD", 1), ft_search_var_in_env(mini->env, "OLDPWD",1));
	// printf("%s\n", getcwd(NULL, 0));
// 	return (0);
// }

int	main(int argc, char **argv, char **envp)
{
	t_mini	*mini;
	t_shell	shell;

	(void)argc;
	(void)argv;
	if (init_shell(&shell) == -1)
		return (EXIT_FAILURE);
	mini = malloc(sizeof(t_mini));
	ft_init_mini(mini);
	ft_create_env_and_path(mini, envp);
		shell.mini = mini;
		read_user_input(&shell);
	clean_shell(&shell);
	mini_free(mini);
}
