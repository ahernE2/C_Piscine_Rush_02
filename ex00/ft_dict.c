/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 05:20:50 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/07 21:47:29 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_word_len(int i, char *file)
{
	int		len;
	int		fd;
	char	buffer;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Dict Error\n", 11);
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

char	*ft_get_word_in_dict(int fd, int nb_char, char buffer, char *file)
{
	char	*str;
	int		i;

	i = ft_word_len(nb_char, file);
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

char	*ft_parse_dict_internal(char *str, int fd, char *file)
{
	int		i;
	char	buffer;
	char	*output;

	i = 0;
	while (read(fd, &buffer, 1))
	{
		if (str[i] != buffer && str[i] != '\0')
		{
			ft_go_to_next_line(&fd, &i);
			continue ;
		}
		if ((buffer == ':' || buffer == ' ') && str[i] == '\0')
			output = ft_get_word_in_dict(fd, i, buffer, file);
		if (str[i] == '\0')
		{
			ft_go_to_next_line(&fd, &i);
			continue ;
		}
		i++;
	}
	return (output);
}

char	*ft_parse_dict(char *str, char *file)
{
	int		fd;
	char	*output;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Dict Error\n", 11);
	output = ft_parse_dict_internal(str, fd, file);
	close(fd);
	return (ft_remove_multiple_space(output));
}
