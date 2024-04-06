/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judblanc <judblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:09:23 by judblanc          #+#    #+#             */
/*   Updated: 2024/04/06 19:48:39 by darsalga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	int	nb;
	char	*val;
}		t_list;

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
t_list	*get_dict(char *dict);
long	ft_atoi(char *str);

int	main(int argc, char **argv)
{
	int		i;
	t_list	*dict;
	char	*dict_file;
	char	*nbr;

	i = 0;
	nbr = "-1";
	if (argc == 3)
	{
		dict_file = argv[1];
		nbr = argv[2];
	}
	else if (argc == 2)
	{
		dict_file = "numbers.dict";
		nbr = argv[1];
	}
	else
	{
		write(1, "Invalid number of arguments", 29);
		return (0);
	}
	if (ft_atoi(nbr) > 0)
	{
		dict = get_dict(dict_file);
	}
	return (0);
}
