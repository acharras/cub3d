/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:41:42 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:39:15 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*temp_src;
	char	*temp_dst;

	if (src == NULL && dst == NULL && n != 0)
		return (0);
	temp_src = (char *)src;
	temp_dst = (char *)dst;
	if (src < dst)
	{
		while (n)
		{
			n--;
			temp_dst[n] = temp_src[n];
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
