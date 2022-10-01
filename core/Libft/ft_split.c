/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soandrad <soandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:27:26 by soandrad          #+#    #+#             */
/*   Updated: 2022/10/01 17:24:02 by soandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Counts the amount of words included in the string 's' using the 
/// character 'c' as the delimiter.
/// @param s String where to count the words
/// @param c Delimiter character.
/// @return The amount of words found in 's'.
static int	ft_count_words(const char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c)
			words++;
		i++;
	}
	return (words + 1);
}

static void	*ft_clear(char **data)
{
	free(data);
	return (NULL);
}

/// @brief Reserves with malloc an array of strings as a result from separatong 
/// the string 's' into substrings using a character 'c' as a delimiter. 
/// The array has to finish with a pointer to NULL.
/// @param s String to separate.
/// @param c Delimiter character.
/// @return The array of new strings or NULL if the memory reservation fails.
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	start;
	int		words;
	char	**matrix;

	if (!s)
		return (0);
	matrix = (char **) malloc (sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!matrix)
		return (ft_clear(matrix));
	i = 0;
	words = 0;
	while (s[i] && words < ft_count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start != i)
			matrix[words++] = ft_substr(s, start, (i - start));
	}
	matrix[words] = 0;
	return (matrix);
}
