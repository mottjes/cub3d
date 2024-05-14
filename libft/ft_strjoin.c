/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:22:37 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:26:04 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, len_s1 + 1);
	ft_strlcat(new, s2, len_s1 + len_s2 + 1);
	return (new);
}

/*
int main(void)
{
	char s1[] = "Hello";
	char s2[] = "World";

	printf("%s\n", ft_strjoin(s1, s2));
}
*/

/*
gcc ft_strjoin.c ft_strlen.c ft_strlcpy.c ft_strlcat.c -Wall -Wextra -Werror
*/
