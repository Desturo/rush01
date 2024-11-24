/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:13:22 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 22:37:51 by nschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str);
int		ft_atoi(const char *str);

int	**allocate_views_memory(int size, char **tokens)
{
	int	**views;
	int	i;

	views = (int **)malloc(4 * sizeof(int *));
	if (!views)
	{
		free(tokens);
		return (NULL);
	}
	i = 0;
	while (i < 4)
	{
		views[i] = malloc((size) * sizeof(int));
		if (!views[i++])
		{
			free(tokens);
			return (NULL);
		}
	}
	if (!views)
	{
		free(tokens);
		return (NULL);
	}
	return (views);
}

int	calculate_size(char **tokens)
{
	int	count;

	count = 0;
	while (tokens[count])
		count++;
	if (count % 4 != 0)
	{
		free(tokens);
		return (-1);
	}
	return (count / 4);
}

int	convert_token(char **tokens, int i, int j, int size)
{
	int	output;

	output = ft_atoi(tokens[size * i + j]);
	if (output < 1 || output > size)
	{
		return -1;
	}
	return (output);
}

int	**parse_input(char *input, int *size)
{
	char	**tokens;
	int		**views;
	int		i;
	int		j;

	tokens = ft_split(input);
	if (!tokens)
		return (NULL);
	*size = calculate_size(tokens);
	if (*size == -1)
		return (NULL);
	views = allocate_views_memory(*size, tokens);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < *size)
		{
			int num = convert_token(tokens, i, j, *size);
			if (num == -1)
			{
				free(tokens);
				return NULL;
			}
			views[i][j] = num;
			j++;
		}
		i++;
	}
	free(tokens);
	return (views);
}
