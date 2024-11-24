/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:13:22 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 17:22:29 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str);
int		ft_atoi(const char *str);

int	**parse_input(char *input, int *size)
{
	int		count;
	int		i;
	char	**tokens;
	int		*values;
	int		num;
	int		**views;

	count = 0;
	i = 0;
	tokens = ft_split(input);
	while (tokens[count])
	{
		count++;
	}
	if (count % 4 != 0)
	{
		free(tokens);
		return (NULL);
	}
	*size = count / 4;
	values = (int *)malloc(count * sizeof(int));
	if (!values)
	{
		free(tokens);
		return (NULL);
	}
	for (i = 0; i < count; i++)
	{
		num = ft_atoi(tokens[i]);
		if (num < 1 || num > *size)
		{
			free(values);
			free(tokens);
			return (NULL);
		}
		values[i] = num;
	}
	free(tokens);
	views = (int **)malloc(4 * sizeof(int *));
	if (!views)
	{
		free(values);
		return (NULL);
	}
	i = 0;
	while (i < 4)
	{
		views[i] = malloc((*size) * sizeof(int));
		if (!views[i])
		{
			return (NULL);
		}
		i++;
	}
	if (!views)
	{
		free(values);
		return (NULL);
	}
	i = 0;
	while (i < *size)
	{
		views[0][i] = values[i];
		views[1][i] = values[*size + i];
		views[2][i] = values[*size * 2 + i];
		views[3][i] = values[*size * 3 + i];
		i++;
	}
	return (views);
}
