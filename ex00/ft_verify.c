/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:13:41 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/07 21:59:44 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"	

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
			ft_error("Only digits without signs\n", 26);
		y++;
	}
	return (y);
}
