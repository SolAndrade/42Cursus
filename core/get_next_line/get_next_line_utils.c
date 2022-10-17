#include <stdlib.h>
void	ft_bzero(void *s, int n);

int	ft_strlen(char *str)
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