/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:09:21 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:38:56 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(char *str, int i, char *set, long nbr)
{
	int min;
	int size_set;

	size_set = ft_strlen(set);
	min = 0;
	str[i + 1] = '\0';
	while (i >= min)
	{
		str[i] = set[nbr % size_set];
		nbr = nbr / size_set;
		i--;
	}
	return (str);
}

static void	ft_size(long *nbr, int *i, char *set)
{
	int size_set;

	size_set = ft_strlen(set);
	while (*nbr / size_set > 0)
	{
		*nbr /= size_set;
		*i += 1;
	}
}

char		*ft_itoa_base(long nbr, char *set)
{
	char	*str;
	int		i;
	long	nb_copy;

	i = 1;
	if (nbr < 0)
		nbr = 4294967296 + nbr;
	nb_copy = nbr;
	ft_size(&nbr, &i, set);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i--;
	str = ft_convert(str, i, set, nb_copy);
	return (str);
}
