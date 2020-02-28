/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:17:25 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:39:51 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*str;
	unsigned char	*dst;
	size_t			calc;

	if (!(str = malloc(size * count)))
		return (NULL);
	dst = str;
	calc = count * size;
	while (calc)
	{
		*dst = 0;
		dst++;
		calc--;
	}
	return (str);
}
