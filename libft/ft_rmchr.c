/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 14:57:34 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 16:53:27 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rmchr(char *str, char rm)
{
	char	*s;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (str[++i])
		if (str[i] != rm)
			k++;
	i = -1;
	if (!(s = malloc(sizeof(char) * k + 1)))
		return (NULL);
	while (str[++i] != '\0')
	{
		if (str[i] != rm)
		{
			s[j] = str[i];
			j++;
		}
	}
	s[j] = '\0';
	free(str);
	return (s);
}
