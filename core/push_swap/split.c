/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:03:24 by soandrad          #+#    #+#             */
/*   Updated: 2023/01/13 17:57:05 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct split_data
{
	size_t	i;
	size_t	start;
	int		numbers;
	char	*str;
}	t_split;

int	ft_count_numbers(const char *s)
{
	int	numbers;
	int	i;

	i = 0;
	numbers = 0;
	while (s[i] && s[i] == 32)
		i++;
	while (s[i])
	{
		if (s[i] == 32 && s[i + 1] != '\0' && s[i + 1] != 32)
			numbers++;
		i++;
	}
	return (numbers + 1);
}

int	ft_split(char const *s, t_stacks *astack)
{
	t_split	ts;

	ts.i = 0;
	ts.numbers = 0;
	while (s[ts.i] && ts.numbers < ft_count_numbers(s))
	{
		while (s[ts.i] && s[ts.i] == 32)
			ts.i++;
		ts.start = ts.i;
		while (s[ts.i] && s[ts.i] != 32)
			ts.i++;
		if (ts.start != ts.i)
		{
			ts.str = ft_substr(s, ts.start, (ts.i - ts.start));
			if (ft_check_int(ts.str) == 1)
				return (free(ts.str), 1);
			if (ft_atol(ts.str) == 2147483648)
				return (free(ts.str), 1);
			astack[ts.numbers++].data = ft_atol(ts.str);
			free(ts.str);
		}
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*str;
	size_t	i;

	if (ft_strlen_split(s) < start)
		return (ft_strdup_split(""));
	if (ft_strlen_split(&s[start]) < len)
		len = ft_strlen_split(&s[start]);
	i = 0;
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i < len && s[i + start])
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen_split(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup_split(char *src)
{
	char	*str;
	int		pos;

	pos = 0;
	str = NULL;
	str = (char *) malloc ((ft_strlen_split(src) + 1) * sizeof(char));
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
