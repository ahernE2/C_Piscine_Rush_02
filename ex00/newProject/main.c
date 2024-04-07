/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 03:30:12 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/07 13:45:08 by judblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// Función para imprimir una cadena en la salida estándar
void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

// Función para dividir la cadena en grupos de tres caracteres
void	div_string(int *i, char *str, char *argv, int *l)
{
	int		j;
	int		k;

	k = 0;
	j = 0;
	// Verificar si la longitud actual no es un múltiplo de tres
	if (*i % 3 != 0)
		while (*i % 3 != 0)
		{
			str[k] = argv[*l]; // Copiar el carácter actual de argv a str
			(*i)--; // Decrementar el contador de longitud
			k++;
			(*l)++;
		}
	else
		// Dividir la cadena en grupos de tres caracteres
		while (j < 3)
		{
			str[k] = argv[*l]; // Copiar el carácter actual de argv a str
			j++;
			k++;
			(*l)++;
		}
	str[k] = 0; // Agregar el terminador nulo al final de str
}

// Función para verificar si la cadena es un número válido y devolver su longitud
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
		return (-1); // Si la cadena está vacía, retornar -1
	// Verificar si todos los caracteres son dígitos
	while (argv[i][y])
	{
		if (argv[i][y] < '0' || argv[i][y] > '9')
			return (-1); // Si un carácter no es un dígito, retornar -1
		y++;
	}
	//comp_str_dict(i); // Comparar la cadena con el diccionario
	return (y); // Retornar la longitud de la cadena
}

char	*get_nbr(int argc, char **argv)
{
	if (argc == 2)
		return (argv[1]);
	else
		return (argv[2]);
}

char	*get_dict(int argc, char **argv)
{
	if (argc == 2)
		return ("numbers.dict");
	else
		return (argv[1]);
}

// Función para imprimir las palabras que representan los números
void	print_words(int i, char *nbr, char *dict, char *str)
{
	int	j;
	int	k;
	int	l;

	j = i / 3;
	if (i % 3 != 0)
		j++;
	k = j;
	// Iterar sobre los grupos de tres caracteres
	while (j != 0)
	{
		div_string(&i, str, nbr, &l); // Dividir la cadena en grupos de tres caracteres
		if (j != k && ft_strcmp(str, "000") != 0)
			write(1, ", ", 2); // Imprimir coma y espacio si no es el primer grupo y el grupo actual no es cero
		// Imprimir "and" si es el último grupo y el grupo actual no es cero y no empieza con cero
		if (j == 1 && ft_strcmp(str, "000") != 0 && str[0] == '0' && k != 1)
			write(1, "and ", 4);
		print_number(str, dict); // Imprimir la palabra asociada al grupo de tres caracteres
		if (ft_strcmp(str, "000") != 0 && j != 1)
			ft_print_separator_with_space(j, dict); // Imprimir el separador con espacio si no es el último grupo
		j--; // Decrementar el contador de grupos
	}
	write(1, "\n", 1); // Imprimir nueva línea al final
}

// Función principal
int	main(int argc, char **argv)
{
	char	*str;
	char	*nbr;
	char	*dict;
	int		i;

	i = check_args(argc, argv); // Verificar la validez de la cadena y obtener su longitud
	if (i == -1)
	{
		ft_error();
		return (0);
	}
	nbr = get_nbr(argc, argv);
	dict = get_dict(argc, argv);
	str = (char *)malloc(sizeof(char) * 4); // Asignar memoria para una cadena de tamaño 4
	print_words(i, nbr, dict, str); // Imprimir las palabras asociadas a los números en la caden
	return (0);
}
