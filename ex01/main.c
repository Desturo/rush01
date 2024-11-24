/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:59:36 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/23 17:01:04 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_puterr(char *str);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_puterr("Invalid number of arguments, requiered only 1 argument!\n");
		return (1);
	}
	return (0);
}
