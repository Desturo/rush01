/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:11:58 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 15:13:38 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*ft_skip_whitespace(char *str)
{
	while (*str && ft_is_whitespace(*str))
		str++;
	return (str);
}

char	*ft_skip_non_whitespace(char *str)
{
	while (*str && !ft_is_whitespace(*str))
		str++;
	return (str);
}

int	ft_wordlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_whitespace(str[i]))
		i++;
	return (i);
}

int	ft_count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		str = ft_skip_whitespace(str);
		if (*str && !ft_is_whitespace(*str))
		{
			count++;
			str = ft_skip_non_whitespace(str);
		}
	}
	return (count);
}

char	*ft_allocate_word(char *str)
{
	char	*word;
	int		i;
	int		word_len;

	word_len = ft_wordlen(str);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	i = 0;
	while (i < word_len)
	{
		word[i] = str[i];
		i++;
	}
	word[word_len] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_count_words(str) + 1));
	while (*str)
	{
		str = ft_skip_whitespace(str);
		if (*str && !ft_is_whitespace(*str))
		{
			arr[i] = ft_allocate_word(str);
			i++;
			str = ft_skip_non_whitespace(str);
		}
	}
	arr[i] = NULL;
	return (arr);
}
