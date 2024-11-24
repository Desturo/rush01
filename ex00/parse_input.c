/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:13:22 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 18:45:25 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char *str);
int		ft_atoi(const char *str);
void	ft_puterr(char *str);

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
		if (!views[i])
		{
			free(tokens);
			return (NULL);
		}
		i++;
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
		ft_puterr("views combinations is not correct\n");
		exit(1);
	}
	return (count / 4);
}

int	**parse_input(char *input, int *size)
{
	char	**tokens;
	int		**views;
	int		num;
	int		i;
	int		j;

	tokens = ft_split(input);
	*size = calculate_size(tokens);
	views = allocate_views_memory(*size, tokens);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < *size)
		{
			num = ft_atoi(tokens[*size * i + j]);
			if (num < 1 || num > *size)
			{
				free(tokens);
				return (NULL);
			}
			views[i][j] = num;
			j++;
		}
		i++;
	}
	free(tokens);
	return (views);
}
