/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:01:53 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:39:04 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	str = s;
	while (n != 0)
	{
		if (c == (char)*str)
		{
			return ((char *)str);
		}
		str++;
		n--;
	}
	return (0);
}
