/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:13:41 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/07 23:06:06 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"	

int	ft_verif_dict_lenght(char *file)
{
	int		i;
	int		j;
	int		fd;
	char	buffer;

	j = 0;
	i = -1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Dict Error\n", 11);
	while (read(fd, &buffer, 1))
	{
		if (buffer == ' ' || buffer == ':')
		{
			if (i > j)
				j = i;
			ft_go_to_next_line(&fd, &i);
			continue ;
		}
		i++;
	}
	return (j + 2);
}

void	comp_str_dict(int len, char *file)
{
	int	len_max;

	len_max = ft_verif_dict_lenght(file);
	if (len_max < len)
		ft_error("Dict Error\n", 11);
}

int	check_args(int argc, char **argv)
{
	int		i;
	int		y;
	char	*file;

	i = 0;
	y = 0;
	file = "numbers.dict";
	if (argc == 2)
		i = 1;
	else if (argc == 3)
	{
		i = 2;
		file = argv[1];
	}
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
	comp_str_dict(y, file);
	return (y);
}
