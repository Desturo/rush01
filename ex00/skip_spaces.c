/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_spaces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschneid <nschneid@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:08:02 by kaahmed           #+#    #+#             */
/*   Updated: 2024/11/24 22:57:28 by nschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	*ft_skip_whitespace(char *str)
{
	if (*str && ft_is_whitespace(*str))
		str++;
	return (str);
}

char	*ft_skip_non_whitespace(char *str)
{
	while (*str && !ft_is_whitespace(*str))
		str++;
	return (str);
}
