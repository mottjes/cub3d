/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:57:37 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/25 15:28:05 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
compares s1 and s2 lexicographically, but not more than n characters
Return:
	an integer greater than, equal to, or less than 0,
    according as s1 is greater than, equal to, or less than s2
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	diff;

	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 != '\0' && n != 1)
	{
		++s1;
		++s2;
		n--;
	}
	diff = ((unsigned char)*s1 - (unsigned char)*s2);
	return (diff);
}

/*
int main(void)
{
	char s1[] = "test";
	char s2[] = "test";
	int n;

	n = 3;
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1, s2, n));
}
*/

/*
gcc ft_strncmp.c -Wall -Wextra -Werror
*/