/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:20:51 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:49 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Outputs the string ’s’ to the given file descriptor
followed by a newline
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

/*
int main(void)
{
	char s[] = "Hello World";
	int fd = 1;
	
	ft_putendl_fd(s, fd);
}
*/

/*
gcc ft_putendl_fd.c -Wall -Wextra -Werror
*/
