/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:13:22 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 23:06:52 by nschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (-1);
	}
	return (output);
}

int	**assign_views(int size, char **tokens)
{
	int	**views;
	int	num;
	int	i;
	int	j;

	views = allocate_views_memory(size, tokens);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < size)
		{
			num = convert_token(tokens, i, j, size);
			if (num == -1)
			{
				free(tokens);
				return (NULL);
			}
			views[i][j] = num;
			j++;
		}
		i++;
	}
	return (views);
}

int	**parse_input(char *input, int *size)
{
	char	**tokens;
	int		**views;

	tokens = ft_split(input);
	if (!tokens)
		return (NULL);
	*size = calculate_size(tokens);
	if (*size == -1)
		return (NULL);
	views = assign_views(*size, tokens);
	free(tokens);
	return (views);
}
