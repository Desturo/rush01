/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:58:25 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 18:11:26 by kaahmed          ###   ########.fr       */
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
			exit(1);
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
