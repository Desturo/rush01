/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_puzzle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:52:47 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 21:50:09 by nschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_unique_value(int **grid, int size, int value, int cords[2]);
bool	is_valid_view(int **props[2], int size, int row, int col);

bool	solve_puzzle(int **props[2], int size, int row, int col)
{
	int	value;
	int	**grid;
	int	cords[2];

	grid = props[0];
	if (row == size)
		return (true);
	if (col == size)
		return (solve_puzzle(props, size, row + 1, 0));
	value = 1;
	while (value <= size)
	{
		cords[0] = row;
		cords[1] = col;
		if (is_unique_value(grid, size, value, cords))
		{
			grid[row][col] = value;
			if (is_valid_view(props, size, row, col)
				&& solve_puzzle(props, size, row, col + 1))
				return (true);
			grid[row][col] = 0;
		}
		value++;
	}
	return (false);
}
