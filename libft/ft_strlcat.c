/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:23:16 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:41:47 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned	int	dst_len;
	unsigned	int i;

	dst_len = ft_strlen(dst);
	i = 0;
	if (dst_len > size)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && size - dst_len > 1)
	{
		dst[dst_len + i] = src[i];
		size--;
		i++;
	}
	dst[dst_len + i] = '\0';
	return (ft_strlen(src) + dst_len);
}
