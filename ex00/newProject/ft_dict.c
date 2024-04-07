/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 05:20:50 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/07 13:35:16 by judblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// Estructura para representar un par clave-valor
typedef struct Nodo {
	char	clave[50];
	char	valor[50];
	struct	Nodo *siguiente;
}	Nodo;

// Función para calcular la longitud de una palabra en el diccionario
int	ft_word_len(int i, char *file)
{
	int		len;
	int		fd;
	char	buffer;

    len = 0;
    // Abrir el archivo de diccionario
    fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0); // Retornar 0 si hay un error al abrir el archivo
    // Leer el archivo hasta llegar a la posición i
	while (i-- > 0)
        read(fd, &buffer, 1);
    // Saltar los espacios
	while (read(fd, &buffer, 1) && buffer == ' ')
        ;
    // Contar los caracteres de la palabra
	while (read(fd, &buffer, 1) && buffer != '\n')
        len++;
    // Retornar la longitud de la palabra
	return (len);
}

// Función para obtener una palabra del diccionario
char	*ft_get_word_in_dict(int fd, int nb_char, char buffer, char *file)
{
	char	*str;
	int		i;

    // Calcular la longitud de la palabra
    i = ft_word_len(nb_char, file);
    // Asignar memoria para la palabra
    str = (char *)malloc(sizeof(char) * (i + 1));
    // Saltar los espacios
	while (buffer == ' ')
        read(fd, &buffer, 1);
    // Leer la palabra
	while (buffer != '\n')
    {
        str[i++] = buffer;
        read(fd, &buffer, 1);
    }
    // Agregar el terminador nulo al final de la palabra
    str[i] = '\0';
    // Retornar la palabra
	return (str);
}

// Función para avanzar al siguiente salto de línea en el archivo
void	ft_go_to_next_line(int *fd, int *i)
{
	char	buffer;
    // Leer el archivo hasta encontrar el próximo salto de línea
	while (read(*fd, &buffer, 1))
    {
		if (buffer == '\n')
			break;
    }
    // Reiniciar el contador i
    *i = 0;
}

// Función para eliminar espacios múltiples de una cadena
char	*ft_remove_multiple_space(char *str)
{
	char	*str_cpy;
	int		len;
	int		i;
	int		j;

    // Obtener la longitud de la cadena
    len = 0;
	while (str[len] != '\0')
        len++;
    // Asignar memoria para la cadena copiada
    str_cpy = (char *)malloc(sizeof(char) * (len + 100));
    // Inicializar los índices
    i = 1;
    j = 1;
    // Copiar el primer carácter
    str_cpy[0] = str[0];
    // Copiar los caracteres restantes, omitiendo los espacios duplicados
	while (str[i] != '\0')
    {
		if (!(str[i] == ' ' && str[i - 1] == ' '))
        {
            str_cpy[j] = str[i];
            j++;
        }
        i++;
    }
    // Agregar el terminador nulo al final de la cadena
    str_cpy[j] = '\0';
    // Realizar una realocación de memoria (no implementada aquí)
    // ft_realloc(&str_cpy, '-');
    // Retornar la cadena modificada
	return str_cpy;
}

// Función para analizar el diccionario y obtener una palabra asociada a una cadena
char	*ft_parse_dict(char *str, char *file)
{
	int		fd;
	int		i;
	char	buffer;
	char	*output;

    // Abrir el archivo de diccionario
    fd = open(file, O_RDONLY);
	if (fd == -1)
		return 0; // Retornar 0 si hay un error al abrir el archivo
    // Inicializar el contador i
	i = 0;
    // Leer el archivo
	while (read(fd, &buffer, 1))
	{
        // Verificar si el carácter actual no coincide con el carácter de la cadena
		if (str[i] != buffer && str[i] != '\0')
		{
            // Ir al próximo salto de línea en el archivo
			ft_go_to_next_line(&fd, &i);
		continue;
		}
        // Verificar si el carácter es ':' o ' ' y la cadena está vacía
		if ((buffer == ':' || buffer == ' ') && str[i] == '\0')
            // Obtener la palabra asociada en el diccionario
			output = ft_get_word_in_dict(fd, i, buffer, file);
        // Verificar si la cadena está vacía
		if (str[i] == '\0')
		{
            // Ir al próximo salto de línea en el archivo
			ft_go_to_next_line(&fd, &i);
		continue;
		}
        // Incrementar el contador i
		i++;
	}
    // Eliminar los espacios múltiples de la palabra obtenida
	return (ft_remove_multiple_space(output));
}
