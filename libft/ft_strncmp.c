/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:57:31 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:42:01 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int					comp;
	unsigned int		i;
	unsigned const char	*str1;
	unsigned const char	*str2;

	i = 0;
	str1 = (unsigned const char*)s1;
	str2 = (unsigned const char*)s2;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] == str2[i])
			i++;
		else
		{
			comp = (str1[i] - str2[i]);
			return (comp);
		}
	}
	return (0);
}
