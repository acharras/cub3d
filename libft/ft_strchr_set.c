/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:00:47 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:40:08 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_set(const char *s, char *set)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == set[i])
			return ((char*)s);
		else
			i++;
		if (set[i] == '\0')
		{
			s++;
			i = 0;
		}
	}
	if (set[i] == '\0' && *s == '\0')
		return ((char*)s);
	return (NULL);
}
