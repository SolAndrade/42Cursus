#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char *buffer;
	char *str;
	int byte;
	
	//str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
	//buffer = ft_read(buffer, byte, fd);
	if (ft_strlen(buffer) != 0)
		byte = ft_strlen(buffer);
	if (ft_strlen(buffer) == 0)
	{
		buffer = (char *) malloc (BUFFER_SIZE * sizeof(char));
		if (!buffer)
			return (NULL);
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte <= 0)
		{
			free(buffer);
			return (NULL);
		}
	}
	str = buffer;
	//str = ft_strdup(buffer);
	while (!ft_strchr(str, '\n') && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
		{
			free(str);
			return (NULL);
		}
		if (byte > 0)
			str = ft_strjoin(str, buffer);
		if (byte == 0)
			buffer = NULL;
	}
	if (buffer == NULL)
	{
		free(buffer);
		return (str);
	}
	else
	{
		buffer = ft_strchr(str, '\n');
		buffer++;
		if (str[0] == '\n')
			return (NULL);
	}
	return (ft_substr(str, 0, ft_strlen(str) - ft_strlen(buffer) - 1));
}

/*char *ft_read(char *buffer, int byte, int fd)
{
	if (ft_strlen(buffer) == 0)
	{
		buffer = (char *) malloc (BUFFER_SIZE * sizeof(char));
		if (!buffer)
			return (ft_clean(buffer));
		byte = read (fd, buffer, BUFFER_SIZE);
		if (byte <= 0)
			return (ft_clean(buffer));
	}
	return (buffer);
}*/

/*void probar(void)
{
	system("leaks a.out");
}*/

// int main(){
// 	int fd;
// 	char *path = "prueba.dict";
	
// 	fd = open(path, O_RDONLY);
// 	printf("Line: %s", get_next_line(fd));
// 	printf("\nLine: %s", get_next_line(fd));
// 	printf("\nLine: %s", get_next_line(fd));
// 	printf("\nLine: %s", get_next_line(fd));
// 	//atexit(probar);
// 	//return (0);
// }