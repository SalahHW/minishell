/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:22:18 by aherrman          #+#    #+#             */
/*   Updated: 2023/11/04 03:42:55 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_UTILS_H
# define GLOBAL_UTILS_H

// utils_for_char//
int		ft_strcat(char *src, char *dst);
int		ft_only_spaces(char *str);
int		ft_check_char_in_str(char *str, char c);

// utils_for_tab//
char	**add_char_at_back_tab(char **tab, char *str);
char	**ft_ascii_sort(char **str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_tab_size(char **str);
char	**ft_tab_copy(char **str);
void	free_tab(char **tab);

// utils_for_tab2//
char	**ft_replace_in_tab(char **tab, char *str, char *new_str);
char	*ft_tab_on_one_line(char **tab);
int		count_char_in_tab(char **tab);
char	**ft_delete_elem_in_tab(char *str, char **tab);
char	*ft_search_in_tab(char **tab, char *str);

// utils_for_tab3//
char	**ft_change_value_in_var_in_tab(char **tab, char *var, char *value);

// utils_for_env//
char	*ft_search_var_in_env(char **env, char *search, int need);

// utils_for_test//

void	ft_print_tab_for_test(char **tab);

// UTILS //

int		is_quote(char c);
int		is_single_quote(char c);
int		is_double_quote(char c);
int		has_quote(char *str);
int		is_operator(char c);
int		is_redirection(char c);
int		is_pipe(char c);
int		is_redirect_in(char c);
int		is_redirect_out(char c);
int		is_exit_status(char *str);
int		is_variable(char *str);
int		is_token_delimiter(char c);
char	*get_str(char *str_start, char *str_end);

#endif
