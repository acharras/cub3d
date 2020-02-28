/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:53:25 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:42:10 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy_spe(char *str, char const *s1, size_t start, size_t end)
{
	int		i;

	i = 0;
	while (start <= end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_check_char(char *set, char c)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_start(char *set, char *s1)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && (ft_check_char(set, s1[i]) == 1))
		i++;
	return (i);
}

static int	ft_check_end(char *set, char *s1)
{
	int		i;

	i = 0;
	while (s1[i + 1] != '\0')
		i++;
	while (i > 0 && (ft_check_char(set, s1[i]) == 1))
		i--;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	int		size;
	char	*str_void;
	char	*str;

	str_void = NULL;
	if (s1[0] == '\0')
		return ((char*)s1);
	start = ft_check_start((char*)set, (char*)s1);
	end = ft_check_end((char*)set, (char*)s1);
	size = end - start + 1;
	if (s1[start] == '\0')
	{
		if (!(str_void = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		str_void[0] = '\0';
		return (str_void);
	}
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str = ft_strcpy_spe(str, s1, start, end);
	str[size] = '\0';
	return (str);
}
