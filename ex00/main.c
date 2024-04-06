/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judblanc <judblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:09:23 by judblanc          #+#    #+#             */
/*   Updated: 2024/04/06 14:44:54 by judblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	get_dict(char *dict);

void	number_manage(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
	{
		write(1, "Signs are not accepted", 22);
	}
	else
	{
		while (argv[i])
		{
			write(1, &argv[i], 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*dict;

	i = 0;
	dict = " ";
	if (argc == 3)
	{
		dict = argv[1];
		number_manage(argv[2]);
	}
	else if (argc == 2)
	{
		dict = "numbers.dict";
		number_manage(argv[1]);
	}
	else
		write(1, "Invalid number of arguments", 29);
	get_dict(dict);
	return (0);
}
