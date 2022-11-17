/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:10:17 by soandrad          #+#    #+#             */
/*   Updated: 2022/11/11 19:35:58 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

typedef struct gnl_data
{
	char		*buffer;
	char		*tmp;
	char		*line;
	int			byte;
}	t_gnl_data;

char	*get_next_line(int fd)
{
	static char	*rest[4096];
	t_gnl_data	dt;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dt.tmp = ft_strdup(rest[fd]);
	while (ft_find(dt.tmp, '\n') == 0)
	{
		dt.buffer = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(dt.buffer));
		if (!dt.buffer)
			return (free(dt.buffer), NULL);
		dt.byte = read(fd, dt.buffer, BUFFER_SIZE);
		if (dt.byte <= 0)
		{
			rest[fd] = ft_free(rest[fd]);
			if (dt.byte == 0 && dt.tmp)
				return (free(dt.buffer), dt.tmp);
			return (free(dt.tmp), free(dt.buffer), NULL);
		}
		dt.tmp = ft_content(dt.buffer, dt.tmp, dt.byte);
	}
	dt.line = ft_getline(dt.tmp);
	rest[fd] = ft_free(rest[fd]);
	rest[fd] = ft_rest(dt.tmp, '\n');
	return (free(dt.tmp), dt.line);
}

char	*ft_content(char *buffer, char *tmp, int byte)
{
	char	*aux;

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
	return (free(buffer), tmp);
}

char	*ft_free(char *tofree)
{
	free(tofree);
	tofree = NULL;
	return (tofree);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;

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
// 	    printf("dt.Line %i: %s", i++, get_next_dt.line(fd));
// 	return (0);
// }
