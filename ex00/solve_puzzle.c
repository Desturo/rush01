/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_puzzle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:52:47 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 17:54:37 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_unique_value(int **grid, int size, int row, int col, int value);
bool	is_valid_view(int **grid, int size, int **views, int row, int col);

bool	solve_puzzle(int **grid, int size, int **views, int row, int col)
{
	int	value;

	if (row == size)
		return (true);
	if (col == size)
		return (solve_puzzle(grid, size, views, row + 1, 0));
	value = 1;
	while (value <= size)
	{
		if (is_unique_value(grid, size, row, col, value))
		{
			grid[row][col] = value;
			if (is_valid_view(grid, size, views, row, col) && solve_puzzle(grid,
					size, views, row, col + 1))
			{
				return (true);
			}
			grid[row][col] = 0;
		}
		value++;
	}
	return (false);
}
