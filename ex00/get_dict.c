/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judblanc <judblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:36:44 by judblanc          #+#    #+#             */
/*   Updated: 2024/04/06 15:11:10 by judblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void	get_dict(char *dict)
{
    int fd; // Descriptor de archivo
    ssize_t bytes_read;
    char buffer[BUFFER_SIZE];
    // Abrir el archivo
    fd = open(dict, O_RDONLY);
    if (fd == -1)
   	{
        write(2, "Error al abrir el archivo\n", 27);
        exit(EXIT_FAILURE);
    }
    // Leer el contenido del archivo y mostrarlo en la salida estándar
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
        if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read)
		{
            write(2, "Error al escribir en la salida estándar\n", 40);
			close(fd);
            exit(EXIT_FAILURE);
        }
    }
    if (bytes_read == -1)
	{
        write(2, "Error al leer el archivo\n", 26);
		close(fd);
        exit(EXIT_FAILURE);
    }

    // Cerrar el archivo
    if (close(fd) == -1)
	{
        write(2, "Error al cerrar el archivo\n", 27);
		exit(EXIT_FAILURE);
    }
}

