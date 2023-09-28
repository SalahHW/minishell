/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:22:18 by aherrman          #+#    #+#             */
/*   Updated: 2023/09/28 11:37:41 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_UTILS_H
# define GLOBAL_UTILS_H

//utils_for_char//
int		ft_strcmp(char *s1, char *s2);
char	*ft_search_in_tab(char *seach, char **tab);
int		ft_strcat(char *src, char *dst);
int	ft_only_spaces(char *str);
int ft_check_char_in_str(char*str,char c);

//utils_for_tab//
char ** add_char_at_back_tab(char **tab, char *str);
char	**ft_ascii_sort(char **str);
int		ft_tab_size(char **str);
char	**ft_tab_copy(char **str);
void	free_tab(char **tab);

//utils_for_tab2//
char ** ft_replace_in_tab(char ** tab, char *str, char *new_str);
char *ft_tab_on_one_line(char **tab);
int count_char_in_tab(char **tab);
char **ft_delete_elem_in_tab(char *str, char **tab);

//utils_for_env//
char	*ft_search_var_in_env(char *search, char **env, int need);

//utils_for_test//

void	ft_print_tab_for_test(char **tab);

#endif
