/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:31:58 by nschneid          #+#    #+#             */
/*   Updated: 2024/11/24 14:39:36 by nschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_puterr(char *str);

void	put_grid(int grid[4][4]);
int		solve_grid(int x, int y, int grid[4][4], int views[4][4]);
int 	check_allowed(int x, int y, int grid[4][4], int views[4][4], int to_check);
int		check_o_and_f(int x, int y, int c_view[4], int to_check);
int		*get_views(int x, int y, int *views_at_cord, int views[4][4]);
void	read_input(char *str, int views[4][4]);

int	solve_grid(int x, int y, int grid[4][4], int views[4][4])
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
	{
	 	while (counter <= 4) {
			if (check_allowed(x, y, grid, views, counter))
			{
				grid[x][y] = counter;
				if (solve_grid(x, y + 1, grid, views))
					return 1;
				grid[x][y] = 0;
			}
			counter++;
		}
		return 0;
	}
}

int check_o_and_f(int x, int y, int c_view[4], int to_check)
{
	if(((x == 0 && c_view[0] == 1) || (x == 3 && c_view[1] == 1)) && to_check == 4)
		return (1);
	else if(((y == 0 && c_view[2] == 1) || (y == 3 && c_view[3] == 1)) && to_check == 4)
		return (1);
	else if(((x == 0 && c_view[0] == 4) || (x == 3 && c_view[1] == 4)) && to_check == 1)
		return (1);
	else if(((y == 0 && c_view[2] == 4) || (y == 3 && c_view[3] == 4)) && to_check == 1)
		return (1);
	else
	 return (0);
}

int check_allowed(int x, int y, int	grid[4][4], int views[4][4], int to_check)
{
	int c_view[4];
	int counter;
	int	highest;
	int	viewing;
	get_views(x, y, c_view, views);

	counter = 0;
	viewing = 0;
	highest = 0;
	while (counter < 4)
	{
		if (grid[x][counter] == to_check)
			return (0);
		else if (grid[counter][y] == to_check)
			return (0);
		counter++;
	}
	if(check_o_and_f(x, y, c_view, to_check))
		return (1);
	counter = 0;
	while (counter < x)
	{
		if(grid[counter][y] > highest)
		{
			highest = grid[counter][y];
			viewing++;
		}
		printf("Cords: (%d|%d)  Highest: %d  View: %d  To ckeck: %d\n", x, y, highest, viewing ,to_check);
		if (c_view[0] == viewing && to_check < highest)
		{
			printf("Accepted!\n\n");
			return 1;
		}
		counter++;
	}
	if (to_check < highest)
	{
		printf("Denied!\n\n");
		return (0);
	}
	printf("Else! (%d|%d)\n\n",x,y);
	highest = 0;
	counter = 3;
	while (counter > x)
	{
		if(grid[counter][y] > highest)
		{
			highest = grid[counter][y];
			viewing++;
		}
		if (c_view[1] == viewing && to_check < highest)
			return 1;
		counter--;
	}
	if (to_check < highest)
		return (0);

	highest = 0;
	counter = 0;
	while (counter < y)
	{
		if(grid[x][counter] > highest)
		{
			highest = grid[x][counter];
			viewing++;
		}
		if (c_view[2] == viewing && to_check < highest)
			return 1;
		counter++;
	}
	if (to_check < highest)
		return (0);

	highest = 0;
	counter = 3;
	while (counter > y)
	{
		if(grid[x][counter] > highest)
		{
			highest = grid[x][counter];
			viewing++;
		}
		if (c_view[3] == viewing && to_check < highest)
			return 1;
		counter--;
	}
	if (to_check < highest)
		return (0);
	
	return (1);
}

int	*get_views(int x, int y, int *views_at_cord, int views[4][4])
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

void read_input(char *str, int views[4][4])
{
	int i;
	int x;
	int	y;
	int counter;

	counter = 0;
	i = 0;
	x = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= '0' &&  str[i] <= '4'))
		{	
			ft_puterr("Invalid character in input!\n");
			exit(1);
		}
		if (((ft_strlen(str) + 1) / 2) != 16)
		{
			ft_puterr("Invalid number of characters in input!\n");
			exit(1);
		}
		i++;
	}
	while (x < 4)
	{
		while (y < 4)
		{
			views[x][y] = (str[counter * 2]) - 48;
			counter++;
			y++;
		}
		y = 0;
		x++;
	}
}

int	main(int argc, char *argv[])
{
	int	grid[4][4];
	int views[4][4] = {{4,3,2,1}, {1,2,2,2}, {4,3,2,1}, {1,2,2,2}};
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
		ft_puterr("Invalid number of arguments. This program always requiers 1 argument!\n");
		return (1);
	}

	read_input(argv[1], views);
	// if(solve_grid(0,0, grid, views))
	// {
	// 	put_grid(grid);
	// }
	// else
	// {
	// 	put_grid(grid);
	// 	ft_puterr("Unsolvable!\n");
	// 	return (1);
	// }
	// int	c_views[4];
	// get_views(3, 3, c_views, views);
	// printf("ColUp: %d\nColDown: %d\nRowLeft: %d\nRowRight: %d\n", c_views[0], c_views[1], c_views[2], c_views[3]);
	put_grid(views);
	return (0);
}