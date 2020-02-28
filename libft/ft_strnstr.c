/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:26:17 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:42:04 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int k;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		j = 0;
		k = len;
		while (haystack[i + j] == needle[j] && k > 0)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			k--;
			j++;
		}
		i++;
		len--;
	}
	return (0);
}
