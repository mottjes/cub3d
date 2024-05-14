/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:02:58 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:26:40 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string
*/

#include "libft.h"

static int	in(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	first = 0;
	last = ft_strlen(s1);
	while (in(set, s1[first]))
		first++;
	if (first == last)
		return (ft_strdup(""));
	while (in(set, s1[last - 1]))
		last--;
	return (ft_substr(s1, first, last - first));
}

/*
int	main(void)
{
	char *str = "***!***test*****";
	printf("%s\n", ft_strtrim(str, "t*"));
}
*/

/*
gcc ft_strtrim.c ft_strdup.c ft_substr.c ft_strlen.c ft_strlcpy.c 
-Wall -Wextra -Werror
*/
