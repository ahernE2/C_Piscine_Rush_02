/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judblanc <judblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:09:23 by judblanc          #+#    #+#             */
/*   Updated: 2024/04/06 18:36:13 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_dict(char *dict);
long	ft_atoi(char *str);


int	main(int argc, char **argv)
{
	int		i;
	char	*dict;
	char	*nbr;

	i = 0;
	dict = "";
	nbr = -1;
	if (argc == 3)
	{
		dict = argv[1];
		nbr = argv[2];
	}
	else if (argc == 2)
	{
		dict = "numbers.dict";
		nbr = argv[1];
	}
	else
	{
		write(1, "Invalid number of arguments", 29);
		return (0);
	}
	if (ft_atoi(nbr) > 0)
	{
		get_dict(dict);
	}
	return (0);
}
