/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:13:22 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 15:23:14 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str);
int		ft_atoi(const char *str);

int	*parse_input(char *input, int *size)
{
	int		count;
	int		i;
	char	**tokens;
	int		*values;
	int		num;

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
	return (values);
}
