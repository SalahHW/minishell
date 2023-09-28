/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:42:13 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/28 12:09:03 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_for_export(char **tmp)
{
	int	i;
	int	j;

	j = 0;
	while (tmp[j])
	{
		i = 0;
		write(1, "declare -x ", 11);
		while (tmp[j][i])
		{
			if (tmp[j][i] == '=')
			{
				write(1, "=\"", 2);
			}
			else
			{
				write(1, &tmp[j][i], 1);
			}
			i++;
		}
		j++;
		write(1, "\"\n", 2);
	}
	write(1, "\n", 1);
}
void	ft_test(t_mini *mini)
{
	char	**tab;

	(void)mini;
	tab = malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup("=CBBBBB");
	tab[1] = ft_strdup("=AAAAAA");
	tab[2] = ft_strdup("=ACCCCCC");
	tab[3] = NULL;
	ft_print_for_export(tab);
	printf("\n\n\n\n\n");
	ft_print_for_export(ft_ascii_sort(tab));
}

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
	//ft_test(mini);
	shell.mini = mini;
	printf("%s\n", shell.mini->home);
	printf("%s\n", mini->home);
	read_user_input(&shell);
	clean_shell(&shell);
	mini_free(mini);
}
