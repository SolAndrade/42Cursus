/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:53:58 by soandrad          #+#    #+#             */
/*   Updated: 2022/11/11 18:20:36 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_find(char *s, char c);
char	*ft_getline(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_bzero(char *s, int n);
char	*ft_rest(char *s, char c);
char	*ft_free(char *tofree);
char	*ft_content(char *buffer, char *tmp, int byte);
// char	*ft_read(int fd, char *rest, char *tmp);

#endif