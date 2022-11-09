#include "get_next_line.h"

char	*get_next_line(int fd)
{
    static char *rest = NULL;
    char *buffer;
    char *tmp;
    char *aux;
    char *line;
    int byte;

    buffer = NULL;
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
        if (!buffer)
        {
            buffer = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(buffer));
            if (!buffer)
            {
                free(buffer);
                return (NULL);
            }
        }
        byte = read(fd, buffer, BUFFER_SIZE);
        if (byte <= 0)
        {
            if(byte == 0 && tmp != NULL)
            {
                free(rest);
                rest = NULL;
                free(buffer);
                return (tmp);
            }
            if (tmp)
                free(tmp);
            free(buffer);
            return (NULL);
        }
        buffer[byte] = '\0';
        if (!tmp)
        {
            tmp = ft_strdup(buffer);
            if (!tmp)
                return (free(buffer), NULL);
        }
        else
        {
            aux = ft_strjoin(tmp, buffer);
            // if (!aux)
            //     return (free(buffer), NULL);
            free(tmp);
            tmp = ft_strdup(aux);
            // if (!tmp)
            //     return (free(buffer), NULL);
            free(aux);
        }
    }
    if (buffer)
        free(buffer);
    line = ft_getline(tmp);
    if (rest)
    {
        free(rest);
        rest = NULL;
    }
    rest = ft_rest(tmp, '\n'); 
    free(tmp);
    // if (!rest && !line)
    //     return (NULL);
    return (line);
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
//     int loop = 13;
// 	char *path = "prueba.dict";
// 	fd = open(path, O_RDONLY);
//     for(int j = 0; j < loop; j++)
// 	    printf("Line %i: %s", i++, get_next_line(fd));
// 	return (0);
// }