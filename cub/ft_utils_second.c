/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:16:07 by acharras          #+#    #+#             */
/*   Updated: 2020/03/06 15:43:30 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_check_space_next_3(t_cub3d *game, int i, int j)
{
	if (((i - 1) >= 0 && game->map[i - 1] != '\0' && (int)ft_strlen(game->map[i
		- 1]) >= j && game->map[i - 1][j] == 'N') || ((j - 2) >= 0 && game->map
		[i][j - 2] == 'N') || ((j + 2) <= (int)ft_strlen(game->map[i]) &&
		game->map[i][j + 2] == 'N') || (game->map[i + 1] != '\0' && (int)
		ft_strlen(game->map[i + 1]) >= j && game->map[i + 1][j] == 'N'))
	{
		ft_putstr("Error\nMap error : a space and a | N | can't ");
		ft_putstr("be side by side...\n");
		ft_exit(game);
	}
	if (((i - 1) >= 0 && game->map[i - 1] != '\0' && (int)ft_strlen(game->map[i
		- 1]) >= j && game->map[i - 1][j] == 'S') || ((j - 2) >= 0 && game->map
		[i][j - 2] == 'S') || ((j + 2) <= (int)ft_strlen(game->map[i]) &&
		game->map[i][j + 2] == 'S') || (game->map[i + 1] != '\0' && (int)
		ft_strlen(game->map[i + 1]) >= j && game->map[i + 1][j] == 'S'))
	{
		ft_putstr("Error\nMap error : a space and a | S | can't ");
		ft_putstr("be side by side...\n");
		ft_exit(game);
	}
}

static void	ft_check_space_next_2(t_cub3d *game, int i, int j)
{
	if (((i - 1) >= 0 && game->map[i - 1] != '\0' && (int)ft_strlen(game->map[i
		- 1]) >= j && game->map[i - 1][j] == 'W') || ((j - 2) >= 0 && game->map
		[i][j - 2] == 'W') || ((j + 2) <= (int)ft_strlen(game->map[i]) &&
		game->map[i][j + 2] == 'W') || (game->map[i + 1] != '\0' && (int)
		ft_strlen(game->map[i + 1]) >= j && game->map[i + 1][j] == 'W'))
	{
		ft_putstr("Error\nMap error : a space and a | W | can't ");
		ft_putstr("be side by side...\n");
		ft_exit(game);
	}
	if (((i - 1) >= 0 && game->map[i - 1] != '\0' && (int)ft_strlen(game->map[i
		- 1]) >= j && game->map[i - 1][j] == '2') || ((j - 2) >= 0 && game->map
		[i][j - 2] == '2') || ((j + 2) <= (int)ft_strlen(game->map[i]) &&
		game->map[i][j + 2] == '2') || (game->map[i + 1] != '\0' && (int)
		ft_strlen(game->map[i + 1]) >= j && game->map[i + 1][j] == '2'))
	{
		ft_putstr("Error\nMap error : a space and a | 2 | can't ");
		ft_putstr("be side by side...\n");
		ft_exit(game);
	}
}

static void	ft_check_space_next(t_cub3d *game, int i, int j)
{
	if (((i - 1) >= 0 && game->map[i - 1] != '\0' && (int)ft_strlen(game->map[i
		- 1]) >= j && game->map[i - 1][j] == '0') || ((j - 2) >= 0 && game->map
		[i][j - 2] == '0') || ((j + 2) <= (int)ft_strlen(game->map[i]) &&
		game->map[i][j + 2] == '0') || (game->map[i + 1] != '\0' && (int)
		ft_strlen(game->map[i + 1]) >= j && game->map[i + 1][j] == '0'))
	{
		ft_putstr("Error\nMap error : a space and a '0' can't ");
		ft_putstr("be side by side...\n");
		ft_exit(game);
	}
	if (((i - 1) >= 0 && game->map[i - 1] != '\0' && (int)ft_strlen(game->map[i
		- 1]) >= j && game->map[i - 1][j] == 'E') || ((j - 2) >= 0 && game->map
		[i][j - 2] == 'E') || ((j + 2) <= (int)ft_strlen(game->map[i]) &&
		game->map[i][j + 2] == 'E') || (game->map[i + 1] != '\0' && (int)
		ft_strlen(game->map[i + 1]) >= j && game->map[i + 1][j] == 'E'))
	{
		ft_putstr("Error\nMap error : a space and a | E | can't ");
		ft_putstr("be side by side...\n");
		ft_exit(game);
	}
}

void		ft_check_space(t_cub3d *game, int i, int j)
{
	if (game->map[i][j] == ' ' && (j - 1) == -1 && ((j + 1) <=
		(int)ft_strlen(game->map[i]) && game->map[i][j + 1] != ' '))
	{
		ft_putstr("Error\nMap error : missing space or number of space ");
		ft_putstr("is not pair at the beginning...\n");
		ft_exit(game);
	}
	if (game->map[i][j] == ' ' && (j - 1) == -1 && ((j + 1) <=
		(int)ft_strlen(game->map[i]) && game->map[i][j + 1] == ' '))
		game->map[i][j] = '1';
	else if (game->map[i][j] == ' ' && ((j - 1) >= 0 &&
		game->map[i][j - 1] == ' ') && ((j + 1) <= (int)ft_strlen(game->map[i])
		&& game->map[i][j + 1] == ' '))
	{
		ft_check_space_next(game, i, j);
		ft_check_space_next_2(game, i, j);
		ft_check_space_next_3(game, i, j);
		game->map[i][j] = '1';
	}
}

int			ft_check_full_arg(t_cub3d *game, char *line)
{
	if (game->north != NULL && game->south != NULL &&
			game->east != NULL && game->west != NULL && game->sprite != NULL &&
			game->color_floor != -1 && game->color_ceiling != -1 &&
			game->width != -1 && game->height != -1)
	{
		if (line[0] == '\0' && game->newline_map == 1)
		{
			ft_putstr("Error\nNew line in the map...\n");
			ft_exit(game);
		}
		game->newline_map = 0;
		if (line[0] == '1')
			game->newline_map = 1;
		if (line[0] == '\0')
			return (2);
		game->check_map++;
		return (1);
	}
	return (0);
}
