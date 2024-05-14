/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:20:19 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/25 13:51:32 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’
The substring begins at index ’start’ and is of
maximum size ’len’
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

/*
int main(void)
{
	char str[] = "Hello this is a test";
	size_t len = 6;
	unsigned int start = 5;
	
	ft_substr(str, start, len);
	printf("%s\n", ft_substr(str, start, len));
}
*/

/*
gcc ft_substr.c ft_strlen.c ft_strdup.c ft_strlcpy.c -Wall -Wextra -Werror
*/
