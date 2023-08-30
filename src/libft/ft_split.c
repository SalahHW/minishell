/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:11:34 by aherrman          #+#    #+#             */
/*   Updated: 2023/07/18 15:24:00 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_word(char const *s, char c, size_t x)
{
	size_t	j;
	size_t	i;
	char	*word;
	size_t	nb_word;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		while ((s[i] == c) && (s[i]))
		i++;
		j = i;
		while ((s[i] != c) && (s[i]))
			i++;
		if (x == nb_word)
		{
			word = ft_substr(s, j, (i - j));
			return (word);
		}
		if (i > j)
		nb_word++;
	}
	return (NULL);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	nb_word;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			nb_word++;
		while ((s[i] != c) && (s[i]))
			i++;
	}
	return (nb_word);
}

void	ft_free_split(char **word)
{
	size_t	i;

	i = 0;
	while (word[i])
	{
		free(word[i]);
			i++;
	}
	free(word);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	size_t	x;
	size_t	nb_word;

		x = 0;
	if (s == NULL)
		return (NULL);
	nb_word = (ft_count(s, c));
	word = malloc(sizeof(const char *) * (nb_word + 1));
	if (word == 0)
		return (0);
	while (nb_word > x)
	{
		word[x] = ft_word(s, c, x);
		if (word[x] == 0)
		{
			ft_free_split(word);
			return (0);
		}
		x++;
	}
	word[x] = 0;
	return (word);
}
