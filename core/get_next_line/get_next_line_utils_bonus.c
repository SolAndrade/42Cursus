/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:04:15 by soandrad          #+#    #+#             */
/*   Updated: 2022/11/11 19:40:17 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	s1 = NULL;
	free(s1);
	return (NULL);
}

char	*ft_rest(char *s, char c)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] != c)
	{
		if (s[i++] == '\0')
			return (NULL);
	}
	i++;
	if (s[i] == '\0')
		return (NULL);
	rest = (char *) malloc ((ft_strlen(s) - (i)) * sizeof(rest));
	if (!rest)
		return (NULL);
	while (s[i])
		rest[j++] = s[i++];
	rest[j] = '\0';
	if (ft_strlen(rest) == 0)
		return (free(rest), NULL);
	return (rest);
}

int	ft_find(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	if (!src)
		return (NULL);
	str = (char *) malloc ((ft_strlen(src) + 1) * sizeof(str));
	if (!str)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
