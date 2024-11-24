/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:55:14 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 17:52:18 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
void	ft_puterr(char *str)
{
	write(2, str, ft_strlen(str));
}

void	print_grid(int **grid, int size)
{
	char c;

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
