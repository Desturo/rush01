/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:46:03 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 22:03:12 by nschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

bool	is_unique_value(int **grid, int size, int value, int cords[2])
{
	int	i;
	int	row;
	int	col;

	row = cords[0];
	col = cords[1];
	i = 0;
	while (i < size)
	{
		if (grid[row][i] == value || grid[i][col] == value)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_correct_amount_visible(int *line, int no_of_view, int size,
		bool is_reverse)
{
	int	count;
	int	max_height;
	int	i;
	int	cur_height;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < size)
	{
		if (is_reverse)
			cur_height = line[size - 1 - i];
		else
			cur_height = line[i];
		if (cur_height > max_height)
		{
			max_height = cur_height;
			count++;
		}
		i++;
	}
	return (count == no_of_view);
}

bool	is_valid_view(int ***props, int size, int row, int col)
{
	int	*line;
	int	i;
	int	**grid;
	int	**views;

	grid = props[0];
	views = props[1];
	line = (int *)malloc(size * sizeof(int));
	if (row == size - 1)
	{
		i = -1;
		while (++i < size)
			line[i] = grid[i][col];
		if (!is_correct_amount_visible(line, views[0][col], size, false)
			|| !is_correct_amount_visible(line, views[1][col], size, true))
			return (false);
	}
	if (col == size - 1)
	{
		if (!is_correct_amount_visible(grid[row], views[2][row], size, false)
			|| !is_correct_amount_visible(grid[row], views[3][row], size, true))
			return (false);
	}
	free(line);
	return (true);
}

bool	is_valid_constraints(int **views, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (views[0][i] + views[1][i] > size + 1 || views[2][i]
			+ views[3][i] > size + 1)
		{
			return (false);
		}
		i++;
	}
	return (true);
}
