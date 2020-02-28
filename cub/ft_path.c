/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:49:35 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 18:24:17 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_path_next_2(t_cub3d *game, char *line, int i)
{
	if (line[0] == 'W' && line[1] == 'E')
	{
		if (line[i] != '.')
		{
			ft_putstr("Error\nArgument | WE | can only save texture path...\n");
			ft_exit(game);
		}
		if (!(game->west = ft_strdup(ft_strchr(line, '.'))))
			ft_exit(game);
		game->verif_we++;
	}
	if (line[0] == 'S' && line[1] == ' ')
	{
		if (line[i] != '.')
		{
			ft_putstr("Error\nArgument | S | can only save texture path...\n");
			ft_exit(game);
		}
		if (!(game->sprite = ft_strdup(ft_strchr(line, '.'))))
			ft_exit(game);
		game->verif_sp++;
	}
}

static void	ft_path_next(t_cub3d *game, char *line, int i)
{
	if (line[0] == 'S' && line[1] == 'O')
	{
		if (line[i] != '.')
		{
			ft_putstr("Error\nArgument | SO | can only save texture path...\n");
			ft_exit(game);
		}
		if (!(game->south = ft_strdup(ft_strchr(line, '.'))))
			ft_exit(game);
		game->verif_so++;
	}
	if (line[0] == 'E' && line[1] == 'A')
	{
		if (line[i] != '.')
		{
			ft_putstr("Error\nArgument | EA | can only save texture path...\n");
			ft_exit(game);
		}
		if (!(game->east = ft_strdup(ft_strchr(line, '.'))))
			ft_exit(game);
		game->verif_ea++;
	}
}

void		ft_path(t_cub3d *game, char *line)
{
	int	i;

	i = 2;
	if (line[0] != '\0')
		while (line[i] == ' ')
			i++;
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (line[i] != '.')
		{
			ft_putstr("Error\nArgument | NO | can only save texture path...\n");
			ft_exit(game);
		}
		if (!(game->north = ft_strdup(ft_strchr(line, '.'))))
			ft_exit(game);
		game->verif_no++;
	}
	ft_path_next(game, line, i);
	ft_path_next_2(game, line, i);
	if (game->verif_no > 1 || game->verif_so > 1 || game->verif_ea > 1 ||
			game->verif_we > 1 || game->verif_sp > 1)
	{
		ft_putstr("Error\nToo many argument | NO | SO | EA | WE | S |...\n");
		ft_exit(game);
	}
}
