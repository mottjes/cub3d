/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:29:47 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/25 14:36:07 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
identical to strchr(), except it locates the last occurence of c
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	character;
	char	*ptr;

	character = (char)c;
	ptr = (NULL);
	while (*s)
	{
		if (*s == character)
			ptr = (char *)s;
		s++;
	}
	if (character == '\0')
		ptr = (char *)s;
	return (ptr);
}

/*
int main(void)
{
	char str[] = "This is a test";
	int c;

	c = 'i';
	printf("%s\n", ft_strrchr(str, c));
	printf("%s\n", strrchr(str, c));
}
*/

/*
gcc ft_strrchr.c ft_strlen.c -Wall -Wextra -Werror
*/
