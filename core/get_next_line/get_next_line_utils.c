#include <stdlib.h>
#include <stdio.h>
void	ft_bzero(void *s, int n);
char	*ft_strdup(char *src);

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = 0;
	printf("%s", s2);
	str = (char *) malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	if (str && (s1 || s2))
	{
		while (*s1)
		{
			str[i] = *s1++;
			i++;
		}
		while (*s2)
		{
			str[i] = *s2++;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}

void	*ft_calloc(int count, int size)
{
	int		*arr;

	arr = (int *) malloc (count * size);
	if (arr)
		ft_bzero(arr, (count * size));
	return (arr);
}

void	ft_bzero(void *s, int n)
{
	int				zero;
	int			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	zero = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ret;

	ret = (unsigned char)c;
	if (ret >= 0 && ret <= 255)
	{
		while (*s != ret)
		{
			if (*s == '\0')
				return (0);
			s++;
		}
	}
	return ((char *)s);
}

void	*ft_clean(void *array)
{
	char	*str;

	str = (char *) array;
	free(str);
	return (NULL);
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
}