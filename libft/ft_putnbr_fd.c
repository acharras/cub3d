/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:31:07 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:39:30 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long i;

	i = n;
	if (i < 0)
	{
		i = i * -1;
		ft_putchar_fd('-', fd);
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
	}
	ft_putchar_fd(('0' + (i % 10)), fd);
}
