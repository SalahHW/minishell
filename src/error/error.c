/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:15:08 by aherrman          #+#    #+#             */
/*   Updated: 2023/10/27 10:23:03 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	error(char *cmd, char *input, int error)
{
	if (error == 0)
		return (error);
	else if (error == -3)
		printf("Minishell: syntax error near unexpected token `newline'\n");
	else if (error == -2)
		printf("Minishell: %s: ambiguous redirect \n", cmd);
	else if (error == 127)
		printf("Minishell: %s: command not found \n", cmd);
	else if (error == -5 && ft_strncmp(cmd, "exit", 4) == 0)
		printf("Minishell: %s: too many arguments\n", cmd);
	else if (error == -5)
		printf("Minishell: %s: `%s': not a valid identifier\n", cmd, input);
	else if (error == -4)
		printf("Minishell: %s: argument numérique nécessaire\n", cmd);
	else if (error == -10)
		printf("Minishell: %s: too many arguments\n", cmd);
	else
		write_error(cmd, input, error);
	return (errno);
}