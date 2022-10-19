#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
# define BUFFER_SIZE 100

//char    *ft_line (char *buffer);
int     ft_strlen(char *str);
//char    *ft_next(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
//void	*ft_calloc(int count, int size);
void	*ft_clean(void *array);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);

typedef struct s_data
{
	int		has_new_line;
	char	*position;
	char	*str;
	char	*res;
	int		linelen;
	size_t	read;
} t_data;

char *get_next_line(int fd)
{
    t_data data;
	static char *buffer;
	data.has_new_line = 0;
	data.linelen = 0;
	data.position = NULL;
	data.res = "";
	char *total_string = NULL;
	
	if (ft_strlen(buffer) == 0)
	{
		buffer = (char *) malloc (BUFFER_SIZE * sizeof(char));
		if (!buffer)
			return (ft_clean(buffer));
		data.read = read (fd, buffer, BUFFER_SIZE);
		if (data.read <= 0)
			return (ft_clean(buffer));
	}
	total_string = ft_strdup(buffer);
	while (!ft_strchr(total_string, '\n') && data.read != 0)
	{
		data.read = read(fd, buffer, BUFFER_SIZE);
		if (data.read < 0)
		{
			//ft_clean(buffer);
			return (ft_clean(total_string));
		}
		if (data.read > 0)
			total_string = ft_strjoin(total_string, buffer);
		if (data.read == 0)
			buffer = NULL;		
		//GESTIONAR EL RESTO DE LA CADENA PARA PROXIMAS LECTURAS
	}
	if (buffer == NULL)
		return (total_string);
	else
	{
		buffer = ft_strchr(total_string, '\n');
		buffer++;
	}
	return (ft_substr(total_string, 0, ft_strlen(total_string) - ft_strlen(buffer) - 1));
}


/*char *ft_line (char *buffer)
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
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    rest = (char *) malloc ((ft_strlen(buffer) - i + 1) * sizeof(char));
    i++;
    while (buffer[i])
        rest[j++] = buffer[i++];
    rest[j] = '\0';
    free(buffer);
    return (rest);
}*/


int main()
{
	int		fd;
	fd = open("prueba.dict", O_RDONLY);
    printf("%s", "FIRST");
    //printf("\nLinea1: '%s'", get_next_line(fd));
    get_next_line(fd);
    printf("\n%s", "SECOND");
    get_next_line(fd);
    //printf("First Line: %s", get_next_line(fd));
    //printf("\nSecond Line: %s", get_next_line(fd));
    return (0);
}