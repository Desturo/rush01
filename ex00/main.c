/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:59:36 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 23:05:41 by nschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

void	ft_puterr(void);
int		**parse_input(char *input, int *size);
void	free_views(int **views);
void	free_grid(int **grid, int size);
void	print_grid(int **grid, int size);
bool	solve_puzzle(int **props[2], int size, int row, int col);
bool	is_valid_constraints(int **views, int size);
int		**init_grid(int size);

bool	check_constraints(int **views, int size)
{
	if (views == NULL)
		return (1);
	if (!is_valid_constraints(views, size))
	{
		ft_puterr();
		return (1);
	}
	return (0);
}

void	run_solver(int **grid, int **views, int size)
{
	int	**props[2];

	props[0] = grid;
	props[1] = views;
	if (solve_puzzle(props, size, 0, 0))
		print_grid(grid, size);
	else
		ft_puterr();
}

int	main(int argc, char **argv)
{
	int	size;
	int	**grid;
	int	**views;

	if (argc != 2)
	{
		ft_puterr();
		return (1);
	}
	views = parse_input(argv[1], &size);
	if (!views)
	{
		ft_puterr();
		return (1);
	}
	if (check_constraints(views, size))
		return (1);
	grid = init_grid(size);
	run_solver(grid, views, size);
	free_views(views);
	free_grid(grid, size);
	return (0);
}
