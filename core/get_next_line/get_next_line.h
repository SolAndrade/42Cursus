#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef FT_GETNEXTLINE_H
# define FT_GETNEXTLINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

char	*get_next_line(int fd);
void	*ft_clean(void *array);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);
//char	*ft_read(char *buffer, int byte, int fd);

#endif