/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:55:52 by mcouppe           #+#    #+#             */
/*   Updated: 2022/01/21 14:57:08 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);

int		ft_strchr_gnl(char *s, int c);
int		ft_strlen_gnl(char *s);

#endif
