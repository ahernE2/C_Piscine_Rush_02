/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judblanc <judblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 14:09:23 by judblanc          #+#    #+#             */
/*   Updated: 2024/04/07 00:56:27 by judblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	int	nb;
	char	*val;
	struct s_list *next;
}		t_list;

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

t_list	*get_dict(char *dict);
long	ft_atoi(char *str);
void printList(t_list* head) {
    char buffer[256]; // Buffer para almacenar la cadena formateada
    t_list *current = head;
    int bytes_written;

    while (current != NULL) {
        // Formatear el número y la cadena en el buffer
        bytes_written = snprintf(buffer, sizeof(buffer), "%d: %s\n", current->nb, current->val);
        
        // Escribir la cadena en la salida estándar
        write(STDOUT_FILENO, buffer, bytes_written);

        current = current->next;
    }
}
			

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
		printList(dict);
	}
	return (0);
}
