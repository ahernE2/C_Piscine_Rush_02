/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 05:20:50 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/07 14:34:48 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

#include "rush02.h"

int	ft_word_len(int i)
{
	int		len;
	int		fd;
	char	buffer;

	len = 0;
	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
		return (0);
	while (i-- > 0)
		read(fd, &buffer, 1);
	while (read(fd, &buffer, 1) && buffer == ' ')
		;
	read(fd, &buffer, 1);
	while (read(fd, &buffer, 1) && buffer == ' ')
		;
	while (read(fd, &buffer, 1) && buffer != '\n')
		len++;
	return (len);
}

char	*ft_get_word_in_dict(int fd, int nb_char, char buffer)
{
	char	*str;
	int		i;

	i = ft_word_len(nb_char);
	str = (char *)malloc(sizeof(char) * (i + 1));
	while (buffer == ' ')
		read(fd, &buffer, 1);
	read(fd, &buffer, 1);
	while (buffer == ' ')
		read(fd, &buffer, 1);
	i = 0;
	while (buffer != '\n')
	{
		str[i] = buffer;
		i++;
		read(fd, &buffer, 1);
	}
	str[i] = '\0';
	return (str);
}

void	ft_go_to_next_line(int *fd, int *i)
{
	char	buffer;

	while (read(*fd, &buffer, 1))
	{
		if (buffer == '\n')
			break ;
	}
	*i = 0;
}

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

char	*ft_parse_dict(char *str, char *file)
{
	int		fd;
	int		i;
	char	buffer;
	char	*output;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (read(fd, &buffer, 1))
	{
		if (str[i] != buffer && str[i] != '\0')
		{
			ft_go_to_next_line(&fd, &i);
			continue ;
		}
		if ((buffer == ':' || buffer == ' ') && str[i] == '\0')
			output = ft_get_word_in_dict(fd, i, buffer);
		if (str[i] == '\0')
		{
			ft_go_to_next_line(&fd, &i);
			continue ;
		}
		i++;
	}
	return (ft_remove_multiple_space(output));
}
