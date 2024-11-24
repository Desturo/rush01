/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:55:14 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 22:12:39 by nschneid         ###   ########.fr       */
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

void	ft_puterr()
{
	write(2, "Error\n", 6);
}

void	print_grid(int **grid, int size)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = grid[i][j] + '0';
			ft_putchar(c);
			if (j < size - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
