/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_one_lint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherrman <aherrman@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:01:29 by aherrman          #+#    #+#             */
/*   Updated: 2023/05/30 09:12:18 by aherrman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	void	ft_tri(const char *str, int *signe, int *i)
{
	while ((str[*i] == '\f') || (str[*i] == '\n') || (str[*i] == ' ')
		|| (str[*i] == '\r') || (str[*i] == '\t') || (str[*i] == '\v'))
	{
		(*i)++;
	}
	if (str[0] == '-')
	{
	*signe *= -1;
	(*i)++;
	}
	else if (str[0] == '+')
		(*i)++;
}

long int	ft_atoi_one_lint(const char *str)
{
	int			signe;
	int			i;
	long int	nb;

	nb = 0;
	i = 0;
	signe = 1;
	ft_tri(str, &signe, &i);
	while ((str[i] >= 48) && (str[i] <= '9'))
	{
	nb += str[i] -48;
	nb *= 10;
	i++;
	}
	nb *= signe;
	return (nb / 10);
}
