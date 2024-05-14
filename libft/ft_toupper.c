/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:20:46 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:26:43 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
convert a lower case to upper case letter if there is one
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
int main(void)
{
	int	c;

	c = 'z';
	printf("%c\n", ft_toupper(c));
	printf("%c\n", toupper(c));
}
*/

/*
gcc ft_toupper.c -Wall -Wextra -Werror
*/
