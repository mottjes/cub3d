/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:02:51 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/25 15:04:14 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The memcmp() function compares byte string s1 against byte string s2
Both strings are assumed to be n bytes long
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char s1[] = "H";
	char s2[] = "Hello world";
	size_t n;

	n = 5;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d\n", memcmp(s1, s2, n));
}
*/

/*
gcc ft_memcmp.c -Wall -Wextra -Werror
*/
