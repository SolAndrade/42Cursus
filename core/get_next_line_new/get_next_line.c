#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char *buffer;
    int byte;
    char *line;

    if (!buffer)
    {
		buffer = (char *) malloc (BUFFER_SIZE * sizeof(char));
        if (!buffer)
        {
            free(buffer);
            return (NULL);
        }
        byte = read(fd, buffer, BUFFER_SIZE);
        if (byte < 0)
        {
            free(buffer);
            return (NULL);
        }
    }
    line = ft_strdup(buffer);
    if(!ft_strchr(line, '\n'))
    {
        read(fd, buffer, BUFFER_SIZE);
        line = ft_strjoin(line, buffer);
    }
    printf("\nLinea completa: %s", line);
    line = ft_substr(line, 0, ft_findidx(line, '\n'));
    buffer = ft_next(buffer);
    //algo esta mal
    return(line);
}

int main()
{
    int fd;
    char *path = "prueba.txt";
	
	fd = open(path, O_RDONLY);
	printf("Line: %s", get_next_line(fd));
	printf("\nLine: %s", get_next_line(fd));
	return (0);
}