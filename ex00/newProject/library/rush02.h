/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 05:45:50 by alejhern          #+#    #+#             */
/*   Updated: 2024/04/07 06:18:09 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_parse_dict(char *str, char *file);
void	print_number(char *str, char *dict);
void	putstr(char *str);
void	print_separator(int j, char *dict);
void	ft_go_to_next_line(int *fd, int *i);
void	ft_error(void);
void	comp_str_dict(int len);
void	ft_remove_start_zeros(char **str);
int		ft_realloc(char **str, char sign);
void	ft_print_separator_with_space(void);

#endif
