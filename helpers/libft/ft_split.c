/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:25:25 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/04 15:19:30 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../headers/libft.h"

int	count_words(char *str, char seperator)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == seperator)
			i++;
		if (str[i])
		{
			words++;
			while (str[i] && str[i] != seperator)
				i++;
		}
	}
	return (words);
}

int	word_len(char *str, char seperator)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] && str[i] != seperator)
	{
		i++;
		len++;
	}
	return (len);
}

char	*copy_words(char *str, char seperator)
{
	int		len;
	int		i;
	char	*word;

	len = word_len(str, seperator);
	i = 0;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**fill_split_array(char **arr, const char *str, char sep, int word)
{
	int	word_idx;

	word_idx = 0;
	while (*str && word_idx < word)
	{
		while (*str && *str == sep)
			str++;
		if (*str)
		{
			arr[word_idx] = copy_words((char *)str, sep);
			if (!arr[word_idx])
				return (NULL);
			str += word_len((char *)str, sep);
			word_idx++;
		}
	}
	arr[word_idx] = NULL;
	return (arr);
}

char	**ft_split(const char *str, char sep)
{
	char	**array;
	int		words;

	if (!str)
		return (NULL);
	words = count_words((char *)str, sep);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	return (fill_split_array(array, str, sep, words));
}
