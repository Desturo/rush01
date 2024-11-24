/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:59:36 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 17:31:06 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_puterr(char *str);
int		**parse_input(char *input, int *size);

#define N 7

// 4x4
int		views41[4][4] = {
	{4, 3, 2, 1}, // column up
	{1, 2, 2, 2}, // column down
	{4, 3, 2, 1}, // row left
	{1, 2, 2, 2}  // row right
};

// 6x6
int		views61[4][N] = {
	{4, 2, 4, 2, 2, 1}, // column up
	{2, 3, 1, 2, 3, 4}, // column down
	{6, 2, 2, 4, 1, 2}, // row left
	{1, 2, 3, 2, 3, 3}  // row right
};

// 7x7
int		views71[4][N] = {
	{4, 2, 1, 2, 2, 4, 3}, // column up
	{2, 3, 3, 3, 4, 3, 1}, // column down
	{2, 2, 3, 3, 3, 1, 2}, // row left
	{3, 5, 3, 2, 2, 4, 1}  // row right
};

bool	is_unique_value(int grid[N][N], int row, int col, int value)
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (grid[row][i] == value || grid[i][col] == value)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

bool	is_correct_amount_visible(int *line, int no_of_view, bool is_reverse)
{
	int	count;
	int	max_height;
	int	i;
	int	cur_height;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < N)
	{
		if (is_reverse)
			cur_height = line[N - 1 - i];
		else
			cur_height = line[i];
		if (cur_height == 0)
			break ;
		if (cur_height > max_height)
		{
			max_height = cur_height;
			count++;
		}
		i++;
	}
	return (count <= no_of_view);
}

bool	is_valid_view(int grid[N][N], int views[4][N], int row, int col)
{
	static int	line[N];
	int			i;

	if (row == N - 1)
	{
		i = 0;
		while (i < N)
		{
			line[i] = grid[i][col];
			i++;
		}
		if (!is_correct_amount_visible(line, views[0][col], false))
			return (false);
		if (!is_correct_amount_visible(line, views[1][col], true))
			return (false);
	}
	if (col == N - 1)
	{
		if (!is_correct_amount_visible(grid[row], views[2][row], false))
			return (false);
		if (!is_correct_amount_visible(grid[row], views[3][row], true))
			return (false);
	}
	return (true);
}

bool	solve(int grid[N][N], int views[4][N], int row, int col)
{
	int	value;

	if (row == N)
		return (true);
	if (col == N)
		return (solve(grid, views, row + 1, 0));
	value = 1;
	while (value <= N)
	{
		if (is_unique_value(grid, row, col, value))
		{
			grid[row][col] = value;
			if (is_valid_view(grid, views, row, col) && solve(grid, views, row,
					col + 1))
			{
				return (true);
			}
			grid[row][col] = 0;
		}
		value++;
	}
	return (false);
}

void	print_grid(int **grid, int size)
{
	char	c;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < size - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

bool	is_valid_constraints(int views[4][N])
{
	int	i;

	i = 0;
	while (i < N)
	{
		if (views[0][i] + views[1][i] > N + 1 || views[2][i] + views[3][i] > N
			+ 1)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	int	size;
	int	*view_values;
	int	**views;
	int	**grid;
	int	i;
	int	j;

	// int	grid[N][N] = {0};
	// int	views[4][size];
	if (argc != 2)
	{
		printf("Usage: %s <input>\n", argv[0]);
		return (1);
	}
	// view_values = parse_input(argv[1], &size);
	// if (!view_values)
	// {
	// 	printf("Error: Invalid input\n");
	// 	return (1);
	// }
	// for (int i = 0; i < size; i++)
	// {
	// 	views[0][i] = view_values[i];
	// 	views[1][i] = view_values[size + i];
	// 	views[2][i] = view_values[size * 2 + i];
	// 	views[3][i] = view_values[size * 3 + i];
	// }
	// free(view_values);
	views = parse_input(argv[1], &size);
	grid = (int **)malloc(size * sizeof(int *));
	i = 0;
	while (i < size)
	{
		grid[i] = (int *)malloc((size) * sizeof(int));
		if (!grid[i])
		{
			return (1);
		}
		i++;
	}
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
	printf("Size: ");
	printf("%d ", size);
	printf("\n");
	printf("\n");
	printf("Top: ");
	for (int i = 0; i < size; i++)
		printf("%d ", views[0][i]);
	printf("\n");
	printf("Bottom: ");
	for (int i = 0; i < size; i++)
		printf("%d ", views[1][i]);
	printf("\n");
	printf("Left: ");
	for (int i = 0; i < size; i++)
		printf("%d ", views[2][i]);
	printf("\n");
	printf("Right: ");
	for (int i = 0; i < size; i++)
		printf("%d ", views[3][i]);
	printf("\n");
	printf("\n");
	printf("\n");
	print_grid(views, size);
	// if (solve(grid, views41, 0, 0))
	// {
	// 	print_grid(grid);
	// }
	// else
	// {
	// 	ft_puterr("Error\n");
	// }
	i = 0;
	while (i < 4)
	{
		free(views[i]);
		i++;
	}
	free(views);
	i = 0;
	while (i < size)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (0);
}
