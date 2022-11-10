#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef FT_GETNEXTLINE_H
# define FT_GETNEXTLINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
int     ft_strlen(char *str);
int     ft_find(char *s, char c);
char    *ft_getline(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*ft_bzero(char *s, int n);
char *ft_rest(char *s, char c);

#endif