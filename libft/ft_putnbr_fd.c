/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:23:50 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:53 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the integer ’n’ to the given file
descriptor
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
}

/*
int main(void)
{
	int n = 42;
	int fd = 1;

	ft_putnbr_fd(n, fd);
	write(fd, "\n", 1);
	n = -42;
	ft_putnbr_fd(n, fd);
	write(fd, "\n", 1);
	n = 0;
	ft_putnbr_fd(n, fd);
	write(fd, "\n", 1);
	n = -2147483648;
	ft_putnbr_fd(n, fd);
	write(fd, "\n", 1);
	n = 2147483647;
	ft_putnbr_fd(n, fd);
	write(fd, "\n", 1);
}
*/

/*
gcc ft_putnbr_fd.c ft_putchar_fd.c -Wall -Wextra -Werror
*/
