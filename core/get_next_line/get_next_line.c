#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
# define BUFFER_SIZE 1000

char *ft_line (char *buffer);
int	ft_strlen(char *str);
char *ft_next(char *buffer);
//char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_calloc(int count, int size);

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    read(fd, buffer, BUFFER_SIZE);
    if (!buffer)
    {
        free(buffer);
        return (NULL);
    }
    line = ft_line(buffer);
    buffer = ft_next(buffer);
    printf("%s\n%s", "rest:", buffer);
    return (line);
}

/*char *ft_read(int fd, char *buffer)
{
    char *temp;
    int byte;

    if (!buffer)
        buffer = ft_calloc(1, 1);
    temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    byte = 1;
    while (byte > 0)
    {
        byte = read(fd, temp, BUFFER_SIZE);
        if (byte == -1)
        {
            free(temp);
            return (NULL);
        }
        //temp[byte] = 0;
        //buffer = ft_free(buffer, temp);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free (temp);
    return (buffer);
}*/

/*char *ft_free(char *buffer, char *buf)
{
    char *temp;

    temp = ft_strjoin(buffer, buf);
    free(buffer);
    return (temp);
}*/

char *ft_line (char *buffer)
{
    char *line;
    int pos;

    pos = 0;
    while (buffer[pos] && buffer[pos] != '\n')
        pos++;
    line = (char *) malloc (pos * sizeof(char));
    pos = 0;
    while (buffer[pos] && buffer[pos] != '\n')
    {
        line[pos] = buffer[pos];
        pos++;
    }
    line[pos] = '\0';
    return (line);
}

char *ft_next(char *buffer)
{
    int i;
    int pos;
    char *rest;

    i = 0;
    while (buffer[pos] && buffer[pos] != '\n')
        pos++;
    rest = ft_calloc((ft_strlen(buffer) - pos + 1), sizeof(char));
    pos++;
    while (buffer[pos])
        rest[i++] = buffer[pos++];
    free(buffer);
    return (rest);
}


int main()
{
	int		fd;
    //char *buffer;
    char *path = "prueba.dict";

	fd = open(path, O_RDONLY);
    if (fd >= 0)
    {
		//read(fd, buffer, 50);
        printf("\nLine: %s", get_next_line(fd));
    }
	printf("\n%s", "pausa");
    printf("\n%s", get_next_line(fd));
    return (0);
}