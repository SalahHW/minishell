/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:36:55 by sbouheni          #+#    #+#             */
/*   Updated: 2023/10/10 09:53:19 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int	parser(t_shell *shell);

int	check_tokens(t_shell *shell);

int	is_valid_command(t_shell *shell, char *cmd);
int	check_file(t_tokenlist *tokens);

#endif
