/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:59:36 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 21:18:04 by nschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <sys/_types/_gid_t.h>
#include <unistd.h>

void	ft_puterr(char *str);
int		**parse_input(char *input, int *size);
void	free_views(int **views);
void	free_grid(int **grid, int size);
void	print_grid(int **grid, int size);
bool	solve_puzzle(int **grid, int size, int **views, int row, int col);
bool	is_valid_constraints(int **views, int size);
int		**init_grid(int size);

int	main(int argc, char **argv)
{
	int	size;
	int	**views;
	int	**grid;
	
	if (argc != 2)
	{
		ft_puterr("Invalid number of arguments\n");
		return (1);
	}
	views = parse_input(argv[1], &size);
	if (!is_valid_constraints(views, size))
	{
		ft_puterr("Invalid view combinations\n");
		return (1);
	}
	grid = init_grid(size);
	if (solve_puzzle(grid, size, views, 0, 0))
		print_grid(grid, size);
	else
		ft_puterr("Error\n");
	free_views(views);
	free_grid(grid, size);
	return (0);
}
