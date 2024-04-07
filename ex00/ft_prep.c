/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judblanc <judblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:08:26 by judblanc          #+#    #+#             */
/*   Updated: 2024/04/07 21:21:55 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	div_string_extra(int *i, char *str, char *nbr, int *l)
{
	int	k;

	k = 0;
	while (*i % 3 != 0)
	{
		str[k] = nbr[*l];
		(*i)--;
		k++;
		(*l)++;
	}
	return (k);
}

int	div_string_perfect(char *str, char *nbr, int *l)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (j < 3)
	{
		str[k] = nbr[*l];
		j++;
		k++;
		(*l)++;
	}
	return (k);
}

void	div_string(int *i, char *str, char *nbr, int *l)
{
	int	k;

	k = 0;
	if (*i % 3 != 0)
	{
		k = div_string_extra(i, str, nbr, l);
	}
	else
	{
		k = div_string_perfect(str, nbr, l);
	}
	str[k] = '\0';
}
