/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 05:36:55 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/25 01:16:26 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int	parser(t_tokenlist *token_list);

int	check_tokens(t_tokenlist *token_list);

int	is_valid_command(char *str);

#endif
