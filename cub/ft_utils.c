/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:17:53 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 16:37:09 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int		ft_alloc_sprite_order(t_cub3d *game)
{
	if (!(game->sp_order = (int *)malloc(sizeof(int) * (game->sp_nbr + 1))))
		ft_exit(game);
	if (!(game->sp_dist = (double *)malloc(sizeof(double) *
		(game->sp_nbr + 1))))
		ft_exit(game);
	game->sp_order[game->sp_nbr] = '\0';
	game->sp_dist[game->sp_nbr] = '\0';
	return (1);
}

int		ft_rm_space(t_cub3d *game)
{
	int		i;

	i = 0;
	while (i < game->map_i)
	{
		if (!(game->map[i] = ft_rmchr(game->map[i], ' ')))
			ft_exit(game);
		i++;
	}
	return (1);
}
