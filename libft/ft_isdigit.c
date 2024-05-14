/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:18:18 by mottjes           #+#    #+#             */
/*   Updated: 2023/05/24 13:22:04 by mottjes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks if an integer is an digit 
*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
int	main(void)
{
	int	c;

	c = '0';
	printf("%d\n", ft_isdigit(c));
	printf("%d\n", isdigit(c));
}
*/

/*
gcc ft_isdigit.c -Wall -Wextra -Werror
*/
