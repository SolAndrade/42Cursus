#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
# define BUFFER_SIZE 100

char    *ft_line (char *buffer);
int     ft_strlen(char *str);
char    *ft_next(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(int count, int size);

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    char *tmp;
    int found;
    int byte;

    found = 0;
    byte = 0;
    buffer = (char *) malloc (BUFFER_SIZE * sizeof(char));
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    while (found == 0)
    {
        byte = read(fd, buffer, BUFFER_SIZE);
        if (!buffer || byte < 0)
        {
            free(buffer);
            return (NULL);
        }
        if (ft_strchr(buffer, '\n') != NULL)
        {
            line = ft_line(buffer);
            found = 1;
        }
        else
            tmp = ft_strjoin(line, tmp);
        buffer = ft_next(buffer);
        printf("%s\n%s", "Rest:", buffer);
    }
    return (line);
}

char *ft_line (char *buffer)
{
    char *line;
    int i;

    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = (char *) malloc (i * sizeof(char));
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char *ft_next(char *buffer)
{
    int j;
    int i;
    char *rest;

    j = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    rest = (char *) malloc ((ft_strlen(buffer) - i + 1) * sizeof(char));
    i++;
    while (buffer[i])
        rest[j++] = buffer[i++];
    free(buffer);
    return (rest);
}


int main()
{
	int		fd;
	fd = open("prueba.dict", O_RDONLY);
    printf("\nLine: %s", get_next_line(fd));
    return (0);
}