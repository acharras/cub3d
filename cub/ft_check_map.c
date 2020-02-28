/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:26:45 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 16:58:02 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

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

int			ft_check_map(t_cub3d *game, char *line)
{
	if (ft_check_full_arg(game, line) == 1 && game->check_map >= 2)
	{
		if (!(game->tmp_map = ft_strjoin_f_s1(game->tmp_map, line)))
			ft_exit(game);
		if (!(game->tmp_map = ft_strjoin_f_s1(game->tmp_map, "\n")))
			ft_exit(game);
		game->map_i++;
	}
	return (1);
}

static void	ft_check_line(t_cub3d *game, int i, int k)
{
	while (game->map[i][k])
	{
		if (game->map[i][k] == 'N' || game->map[i][k] == 'E' ||
				game->map[i][k] == 'W' || game->map[i][k] == 'S')
		{
			if (++game->map_false == 1)
				game->dir_player = game->map[i][k];
			game->posx = (double)k;
			game->posy = (double)i;
		}
		if (game->map[i][k] != '0' && game->map[i][k] != '1' && game->
			map[i][k] != '2' && game->map[i][k] != 'N' && game->map[i][k]
			!= 'S' && game->map[i][k] != 'E' && game->map[i][k] != 'W')
		{
			ft_putstr("Error\nMap error...");
			ft_exit(game);
		}
		if (game->map[i][k++] == '2')
			game->sp_nbr++;
	}
	if (game->map[i][k - 1] != '1')
	{
		ft_putstr("Error\nMap error : no '1' at the end of line...");
		ft_exit(game);
	}
}

static int	ft_all_line(t_cub3d *game, int i, size_t j, int k)
{
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
		{
			ft_putstr("Error\nMap error...");
			ft_exit(game);
		}
		if (ft_strlen(game->map[i]) != j)
		{
			ft_putstr("Error\nMap error...");
			ft_exit(game);
		}
		ft_check_line(game, i, k);
		k = 0;
		i++;
	}
	return (i);
}

int			ft_check_map_error(t_cub3d *game)
{
	int		i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (ft_strcheck_chr(game->map[0], '1') != 0)
	{
		ft_putstr("Error\nMap error...");
		ft_exit(game);
	}
	while (game->map[0][j])
		j++;
	i = ft_all_line(game, i, j, k);
	if (ft_alloc_sprite_order(game) == 0)
		ft_exit(game);
	if (ft_strcheck_chr(game->map[i - 1], '1') != 0 || game->map_false != 1)
	{
		ft_putstr("Error\nMap error...");
		ft_exit(game);
	}
	return (1);
}
