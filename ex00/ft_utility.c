/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 05:51:07 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/07 22:01:24 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_error(char *str, int size)
{
	write(2, str, size);
	exit(1);
}

void	ft_print_separator_with_space(int j, char *dict)
{
	write(1, " ", 1);
	print_separator(j, dict);
}

char	*ft_remove_multiple_space(char *str)
{
	char	*str_cpy;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	str_cpy = (char *)malloc(sizeof(char) * (len + 100));
	i = 1;
	j = 1;
	str_cpy[0] = str[0];
	while (str[i])
	{
		if (!(str[i] == ' ' && str[i - 1] == ' '))
		{
			str_cpy[j] = str[i];
			j++;
		}
		i++;
	}
	str_cpy[j] = '\0';
	ft_realloc(&str_cpy, '-');
	return (str_cpy);
}

void	ft_remove_start_zeros(char **str)
{
	char	*str_cpy;
	int		i;
	int		j;

	str_cpy = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1));
	i = 0;
	j = 0;
	while ((*str)[i] == '0')
		i++;
	while ((*str)[i])
	{
		str_cpy[j] = (*str)[i];
		i++;
		j++;
	}
	if (j == 0)
		str_cpy[j++] = '0';
	str_cpy[j] = '\0';
	*str = str_cpy;
	ft_realloc(str, '-');
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}
