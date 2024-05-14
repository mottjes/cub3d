/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:32:43 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:47 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the character ’c’ to the given file
descriptor
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int main(void)
{
	char c = 'A';
	int fd = 2;
	ft_putchar_fd(c, fd);
}
*/

/*
gcc ft_putchar_fd.c -Wall -Wextra -Werror
*/
