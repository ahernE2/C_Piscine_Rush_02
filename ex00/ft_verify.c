/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:13:41 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/07 21:20:35 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"	

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

int	check_args(int argc, char **argv)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (argc == 2)
		i = 1;
	else if (argc == 3)
		i = 2;
	else
		return (-1);
	if (argv[i][y] == '0')
		ft_remove_start_zeros(&argv[1]);
	if (argv[i][y] == '\0')
		return (-1);
	while (argv[i][y])
	{
		if (argv[i][y] < '0' || argv[i][y] > '9')
			return (-1);
		y++;
	}
	return (y);
}
