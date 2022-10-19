#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data
{
	int		has_new_line;
	char	*position;
	char	*str;
	char	*res;
	int		linelen;
	size_t	read;
} t_data;

void		*ft_clean(void *array);
void		ft_putchar(char c);
void		ft_putstr(char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(char *src);

/*void	*ft_clean(void *array)
{
	char	*str;

	str = (char *) array;
	free(str);
	return (NULL);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		p;

	p = 0;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (str)
	{
		while (p < len && s[p + start])
		{
			str[p] = s[p + start];
			p++;
		}
		str[p] = '\0';
		return (str);
	}
	else
	{
		free(str);
		return (NULL);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*str;
	int		p;

	p = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc((total_len + 1) * sizeof(char));
	if (str)
	{
		while (*s1)
		{
			str[p++] = *s1;
			s1++;
		}
		while (*s2)
		{
			str[p++] = *s2;
			s2++;
		}
		str[p] = '\0';
		return (str);
	}
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (ch >= 0 && ch <= 255)
	{
		while (*s != ch)
		{
			if (*s == '\0')
				return (0);
			s++;
		}
	}
	return ((char *)s);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		pos;

	pos = 0;
	str = NULL;
	str = (char *) malloc ((ft_strlen(src) + 1) * sizeof(char));
	if (str)
	{
		while (src[pos])
		{
			str[pos] = src[pos];
			pos++;
		}
		str[pos] = '\0';
	}
	return (str);
}*/

char	*get_next_line(int fd)
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

// int main(){
// 	int fd;
// 	char *path = "PRUEBA.txt";
	
// 	fd = open(path, O_RDONLY);
// 	if (fd >= 0)
// 	{
// 		printf("\nLine: %s", get_next_line(fd));
// 		printf("\nLine: %s", get_next_line(fd));
// 		printf("\nLine: %s", get_next_line(fd));
// 		printf("\nLine: %s", get_next_line(fd));
// 	}
// 	return (0);
// }