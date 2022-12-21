/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:39:52 by ooussaad          #+#    #+#             */
/*   Updated: 2022/12/21 22:30:31 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static int	count_words(char const *str, char c)
{
	int	num_words;
	int	i;

	num_words = 0;
	i = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i])
	{
		num_words++;
		while (str[i] != c && str[i])
			i++;
		while (str[i] == c && str[i])
			i++;
	}
	return (num_words);
}

static char	*word_grep(char *str, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (str[len] != c && str[len])
		len++;
	word = (char *) malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static int	free_sp(char **arr, int index)
{
	if (arr[index] == NULL)
	{
		while (index != 0)
		{
			free(arr[index - 1]);
			arr[index - 1] = 0;
			index--;
		}
		return (1);
	}
	return (0);
}

static void	words_fl(char **arr, char *str, char c)
{
	int	index;
	int	i;

	i = 0;
	while (str[i] == c)
		i++;
	index = 0;
	while (str[i])
	{
		arr[index] = word_grep(&str[i], c);
		if (free_sp(arr, index))
			return ;
		index++;
		while (str[i] != c && str[i])
			i++;
		while (str[i] == c && str[i])
			i++;
	}
}

char	**ft_split(char const *str, char c)
{
	int		num_words;
	char	**arr;

	if (str == NULL)
		return (NULL);
	num_words = count_words((char *)str, c);
	arr = (char **) ft_calloc(1, (num_words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[num_words] = NULL;
	if (num_words > 0)
		words_fl(arr, (char *)str, c);
	if (arr[0] == NULL && num_words != 0)
	{
		free(arr);
		return (NULL);
	}
	return (arr);
}
