/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:58:25 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 22:13:42 by nschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**allocate_grid_memory(int size)
{
	int	**grid;
	int	i;

	grid = (int **)malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
	{
		grid[i] = (int *)malloc((size) * sizeof(int));
		if (!grid[i])
		{
			return (NULL);
		}
		i++;
	}
	return (grid);
}

int	**init_grid(int size)
{
	int	**grid;
	int	i;
	int	j;

	grid = allocate_grid_memory(size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}
