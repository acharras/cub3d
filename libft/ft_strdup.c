/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:14:50 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:40:24 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*tab;
	size_t		i;
	size_t		len;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	if (!(tab = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
