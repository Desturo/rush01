/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaahmed <kaahmed@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:08:02 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 18:08:08 by kaahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*ft_skip_whitespace(char *str)
{
	while (*str && ft_is_whitespace(*str))
		str++;
	return (str);
}

char	*ft_skip_non_whitespace(char *str)
{
	while (*str && !ft_is_whitespace(*str))
		str++;
	return (str);
}
