/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:25:24 by mottjes           #+#    #+#             */
/*   Updated: 2024/02/06 14:02:51 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
locates first occurrence of needle in
haystack
not more than len characters are searched
Return:
	If needle is an empty string, haystack is returned 
	If needle occurs nowhere in haystack, NULL is returned 
	otherwise a pointer to the first character of the first 
	occurrence of needle is
    returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char haystack[] = "This is a test";
	char needle[] = "is";
	int len;

	len = 4;
	printf("%s\n", ft_strnstr(haystack, needle, len));
	printf("%s\n", strnstr(haystack, needle, len));
}
*/

/*
gcc ft_strnstr.c -Wall -Wextra -Werror
*/