/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:31:51 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:42:43 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_substr_n(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > 0 && s[start] != '\n')
	{
		str[i] = (char)s[start];
		i++;
		start++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

static char		*ft_read(char *str, char *tmp, int fd, int ret)
{
	char		*buff;

	if ((ret = read(fd, NULL, 0)) < 0)
	{
		free(str);
		return (NULL);
	}
	if (!(buff = malloc(sizeof(buff) * (BUFFER_SIZE + 1))))
		return (NULL);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n'))
		{
			if (!(tmp = ft_strjoin_f_s1(str, buff)))
				return (NULL);
			str = tmp;
			free(buff);
			return (str);
		}
		if (!(str = ft_strjoin_f_s1(str, buff)))
			return (NULL);
	}
	free(buff);
	return (str);
}

static int		ft_fill_line(char *str, int i, char **line, char *tmp)
{
	if (i != 0)
	{
		if (!((*line) = ft_substr_n(str, 0, i)))
			return (-1);
		if (!(tmp = ft_strdup(str + i + 1)))
		{
			free(tmp);
			return (-1);
		}
		str = ft_strcpy(str, tmp);
		free(tmp);
	}
	else
	{
		if (!((*line) = ft_strdup("")))
			return (-1);
		if (!(tmp = ft_strdup(str + 1)))
		{
			free(tmp);
			return (-1);
		}
		str = ft_strcpy(str, tmp);
		free(tmp);
	}
	return (0);
}

static int		ft_fill(char *str, int i, char **line, char *tmp)
{
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] != '\0')
	{
		i = 0;
		while (str[i] != '\0' && str[i] != '\n')
			i++;
		ft_fill_line(str, i, line, tmp);
		return (1);
	}
	else
	{
		if (!((*line) = ft_substr_n(str, 0, i)))
			return (-1);
		free(str);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char *str = NULL;
	char		*tmp;
	int			i;
	int			res;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
	{
		if (str)
			free(str);
		return (-1);
	}
	if (str == NULL)
		if (!((str) = ft_strdup("")))
			return (-1);
	tmp = NULL;
	str = ft_read(str, tmp, fd, 0);
	if (str == NULL)
		return (-1);
	i = 0;
	tmp = NULL;
	res = ft_fill(str, i, line, tmp);
	return (res);
}
