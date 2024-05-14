/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:38:52 by mottjes           #+#    #+#             */
/*   Updated: 2024/02/06 14:02:18 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument
Negative numbers must be handled.
*/

#include "libft.h"

static size_t	count_digits(int n)
{
	int	digits;

	digits = 1;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	long	nb;

	nb = n;
	digits = count_digits(n);
	if (n < 0)
	{
		nb *= -1;
		digits++;
	}
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits--)
	{
		str[digits] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*
int	main(void)
{
	int	n;

	n = 0;
	printf("%s\n", ft_itoa(n));
	n = 42;
	printf("%s\n", ft_itoa(n));
	n = -42;
	printf("%s\n", ft_itoa(n));
	n = 2147483647;
	printf("%s\n", ft_itoa(n));
	n = -2147483648;
	printf("%s\n", ft_itoa(n));
}
*/

/*
gcc ft_itoa.c -Wall -Wextra -Werror
*/
