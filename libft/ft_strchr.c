/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:31:14 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/25 12:23:19 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
locates c in a string (\0 is part of the string)
Return:
	a pointer to the first occurance of c
 	or NULL if c does not appear in the string
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	character;
	char	*ptr;

	character = (char)c;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == character)
			return (ptr);
		ptr++;
	}
	if (character == '\0')
		return (ptr);
	return (NULL);
}

/*
int main(void)
{
	char str[] = "This is a test";
	int c;

	c = 't';
	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str, c));
}
*/

/*
gcc ft_strchr.c -Wall -Wextra -Werror
*/
