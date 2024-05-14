/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:11:32 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:24:04 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The bzero() function writes n zeroed bytes to the string s
If n is zero, bzero() does nothing
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
		*ptr++ = 0;
}

/*
int main(void)
{
	size_t n;
	char str[] = "This is a test";
	char str2[] = "This is a test";

	n = 5;
	printf("%s\n", str);
	ft_bzero(str, n);
	printf("%s\n", str);
	printf("%s\n", str2);
	bzero(str2, n);
	printf("%s\n", str2);
}
*/

/*
gcc ft_bzero.c -Wall -Wextra -Werror
*/
