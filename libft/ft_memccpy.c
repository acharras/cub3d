/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:14:53 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:39:01 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *temp_src;
	unsigned char *temp_dst;

	if (src == NULL && dst == NULL && n != 0)
		return (0);
	temp_src = (unsigned char *)src;
	temp_dst = (unsigned char *)dst;
	while (n != 0)
	{
		*temp_dst = *temp_src;
		if (*temp_src == (unsigned char)c)
			return (temp_dst + 1);
		temp_dst++;
		temp_src++;
		n--;
	}
	return (0);
}
