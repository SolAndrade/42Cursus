#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char *rest = NULL;
    char *buffer;
    char *tmp;
    char *aux;
    char *line;
    int byte;

    tmp = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (rest)
    {
        tmp = ft_strdup(rest);
        if (!tmp)
            return (NULL);
    }
    while (ft_find(tmp, '\n') == 0)
    {
        buffer = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(buffer));
        if (!buffer)
            return (free(buffer), NULL);
        byte = read(fd, buffer, BUFFER_SIZE);
        if (byte <= 0)
        {
            rest = ft_free(rest);
            if(byte == 0 && tmp)
                return (free(buffer), tmp);
            return (free(tmp), free(buffer), NULL);
        }
        buffer[byte] = '\0';
        if (!tmp)
            tmp = ft_strdup(buffer);
        else
        {
            aux = ft_strjoin(tmp, buffer);
            free(tmp);
            tmp = ft_strdup(aux);
            free(aux);
        }
        free(buffer);
    }
    line = ft_getline(tmp);
    if (rest)
        rest = ft_free(rest);
    rest = ft_rest(tmp, '\n'); 
    return (free(tmp), line);
}

char *ft_getline(char *buffer)
{
    char *line;
    int i;

    i = 0;
    if (!buffer)
        return (NULL);
    while (buffer[i] != '\n')
        i++;
    line = (char *) malloc ((i + 2) * sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

// int main()
// {
// 	int fd;
//     int i;

//     i = 1;
//     int loop = 6;
// 	fd = open("prueba.dict", O_RDONLY);
//     for(int j = 0; j < loop; j++)
// 	    printf("Line %i: %s", i++, get_next_line(fd));
// 	return (0);
// }