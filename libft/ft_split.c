/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:50:21 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:25:21 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
*/

#include "libft.h"

static	size_t	ft_substr_len(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

static	size_t	ft_count_substr(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static	int	ft_check_and_free(char **strings, int str_index)
{
	if (!strings[str_index])
	{
		while (str_index >= 0)
		{
			free (strings[str_index]);
			str_index--;
		}
		free (strings);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	count_substr;
	char	**strings;
	size_t	str_index;
	size_t	substr_len;
	size_t	i;

	i = 0;
	str_index = 0;
	count_substr = ft_count_substr(s, c);
	strings = (char **)malloc(sizeof(char *) * (count_substr + 1));
	if (!strings)
		return (NULL);
	while (str_index < count_substr)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		substr_len = ft_substr_len(s + i, c);
		strings[str_index] = ft_substr(s, i, substr_len);
		if (!ft_check_and_free(strings, str_index))
			return (NULL);
		str_index++;
		i += substr_len;
	}
	strings[str_index] = NULL;
	return (strings);
}

/*
int main(void)
{
	char str[] = "To be,,, or not to be, that is the question.";
	char **strings = ft_split(str, ',');
	int i = 0;
	
	while (i < 5)
		printf("%s\n", strings[i++]);	
}
*/

/*
gcc ft_split.c ft_strlen.c ft_strlcpy.c ft_substr.c ft_strdup.c 
-Wall -Wextra -Werror
*/
