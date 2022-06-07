/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baura <baura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:29:34 by baura             #+#    #+#             */
/*   Updated: 2022/03/02 19:33:47 by baura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_word_len(const char *word, char c)
{
	int	i;

	i = 0;
	while (word[i] != '\0' && word[i] != c)
		i++;
	return (i);
}

static size_t	ft_word_counter(const char *string, char c)
{
	int	num_word;

	num_word = 0;
	while (*string != '\0')
	{
		if (*string == c)
			string++;
		else
		{
			num_word++;
			while (*string != '\0' && *string != c)
				string++;
		}
	}
	return (num_word);
}

static char	**ft_free_array(char **array, size_t array_place)
{
	while (array_place--)
		free(array[array_place]);
	free(array);
	array = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	array_place;
	char	**array;

	if (!s)
		return (NULL);
	i = 0;
	array_place = 0;
	array = (char **)malloc(sizeof(char *) * (ft_word_counter(s, c) + 1));
	if (array == NULL)
		return (NULL);
	while (array_place < ft_word_counter(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			array[array_place++] = ft_substr(s, i, ft_word_len(&s[i], c));
		if (!array[array_place - 1])
			return (ft_free_array(array, array_place));
		i += ft_word_len(&s[i], c);
	}
	array[array_place] = NULL;
	return (array);
}
