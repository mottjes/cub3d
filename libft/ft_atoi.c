/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:50:33 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:00 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
convert ASCII string to integer
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	number;

	i = 0;
	number = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += str[i] - 48;
		i++;
	}
	return (number * minus);
}

/*
int main(void)
{
	char str[] = "	 -42";

	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
}
*/

/*
gcc ft_atoi.c -Wall -Wextra -Werror
*/
