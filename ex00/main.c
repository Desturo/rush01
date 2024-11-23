/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:31:58 by nschneid          #+#    #+#             */
/*   Updated: 2024/11/23 16:38:42 by nschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	put_grid(int grid[4][4]);
int		solve_grid(int x, int y, int *grid[], int *views[]);
int 	check_allowed(int x, int y, int *grid[], int *views[], int to_check);
int		*get_views(int x, int y, int *views_at_cord, int *views[]);

int	solve_grid(int x, int y, int *grid[], int *views[])
{
	int	counter;
	
	counter = 1;
	if(x == 4)
		return 1;
	else if (y == 4)
		return solve_grid(x + 1, 0, grid, views);
	else if (grid[x][y] != 0)
		return solve_grid(x, y + 1, grid, views);
	else
	 	while (counter <= 4) {
			if (check_allowed(x, y, grid, views, counter))
			{
				grid[x][y] = counter;
				solve_grid(x, y, grid, views);
			}
		}
}

int check_allowed(int x, int y, int *grid[], int *views[], int to_check)
{
	int current_views[4];
	int counter;
	int	viewing;
	int	viewing_counter;
	get_views(x, y, current_views, views);

	counter = 0;
	viewing = 0;
	viewing_counter = 0;
	while (counter < 4)
	{
		if (grid[x][counter] == to_check)
			return (0);
		else if (grid[counter][y] == to_check)
			return (0);
		
		while (viewing_counter < 4)
		{
			if (viewing == current_views[0])
				viewing_counter = 4;
		}
		
	}
	return (0);
}

int	*get_views(int x, int y, int *views_at_cord, int *views[])
{
	views_at_cord[0] = views[0][x];
	views_at_cord[1] = views[1][x];
	views_at_cord[2] = views[2][y];
	views_at_cord[3] = views[3][y];
	return (views_at_cord);
}

void	put_grid(int grid[4][4])
{
	int counter_x;
	int counter_y;

	counter_x = 0;
	counter_y = 0;

	while (counter_x < 4)
	{
		while (counter_y < 4)
		{
			write(1, &"0123456789"[grid[counter_x][counter_y]], 1);
			write(1, " ", 1);
			counter_y++;
		}
		write(1, "\n", 1);
		counter_y = 0;
		counter_x++;
	}
}

int	main(int argc, char *argv[])
{
	argv[0] = NULL;
	int	grid[4][4];
	int views[4][4] = {{0,1,2,3},{20,21,22,23}, {10,11,12,13},{30,31,32,33}};
	// int current_views[4];
	int counter_x = 0;
	int counter_y = 0;
	while (counter_x < 4) {
		while (counter_y < 4) {
			grid[counter_x][counter_y] = 0;
			counter_y++;
		}
		counter_x++;
		counter_y = 0;
	}

	if(argc != 2)
	{
		write(1, "Invalid number of arguments. This program always requiers 1 argument!\n", 70);
		return (1);
	}

	put_grid(grid);
	return (0);
}