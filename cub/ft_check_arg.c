/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:35:56 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 17:11:50 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_check_arg_next_2(t_cub3d *game, char *line, int j)
{
	if ((game->height = ft_atoi(&line[j])) > 1400)
	{
		game->height = 1400;
		ft_putstr("WARNING !\nmap height resized to 1400 because ");
		ft_putstr("height is superior than the limit screen\n");
	}
	if ((game->height = ft_atoi(&line[j])) < 150)
	{
		game->height = 150;
		ft_putstr("WARNING !\nmap height resized to 150 because ");
		ft_putstr("too small height\n");
	}
	j = j + ft_int_len(game->height);
	while (line[j] == ' ')
		j++;
	if (line[j] != '\0')
	{
		ft_putstr("Error\nArgument | R | had a bad format...\n");
		ft_exit(game);
	}
}

static int	ft_check_arg_next(t_cub3d *game, char *line, int j)
{
	while (line[j] == ' ')
		j++;
	if (game->width != -1 || game->height != -1)
	{
		ft_putstr("Error\nMultiple or no argument 'R'...");
		ft_exit(game);
	}
	if ((game->width = ft_atoi(&line[j])) > 2560)
	{
		game->width = 2560;
		ft_putstr("WARNING !\nmap width resized to 2560 because ");
		ft_putstr("width is superior than the limit screen\n");
	}
	if ((game->width = ft_atoi(&line[j])) < 250)
	{
		game->width = 250;
		ft_putstr("WARNING !\nmap width resized to 250 because ");
		ft_putstr("too small width\n");
	}
	j = j + ft_int_len(game->width);
	while (line[j] == ' ')
		j++;
	return (j);
}

void		ft_check_arg(t_cub3d *game, char *line)
{
	int		j;

	j = 1;
	if (line[0] == 'R')
	{
		while (line[j] != '\0')
		{
			if (line[j] != '0' && line[j] != '1' && line[j] != '2' &&
				line[j] != '3' && line[j] != '4' && line[j] != '5' &&
				line[j] != '6' && line[j] != '7' && line[j] != '8' &&
				line[j] != '9' && line[j] != ' ')
			{
				ft_putstr("Error\nArgument | R | had a bad format...\n");
				ft_exit(game);
			}
			j++;
		}
		j = ft_check_arg_next(game, line, 1);
		ft_check_arg_next_2(game, line, j);
	}
	ft_path(game, line);
	ft_colors(game, line);
}
