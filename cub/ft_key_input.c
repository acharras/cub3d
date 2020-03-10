/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:16:09 by acharras          #+#    #+#             */
/*   Updated: 2020/03/10 15:21:06 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

int			key_input(int key, t_cub3d *game)
{
	game->key = key;
	if (game->key == 53)
		ft_exit(game);
	if (game->key == 123)
		game->left_arrow = 1;
	if (game->key == 124)
		game->right_arrow = 1;
	if (game->key == 0)
		game->press_a = 1;
	if (game->key == 2)
		game->press_d = 1;
	if (game->key == 1)
		game->press_s = 1;
	if (game->key == 13)
		game->press_w = 1;
	if (game->key == 49)
		game->press_shift = 1;
	return (1);
}

int			key_release(int key, t_cub3d *game)
{
	game->key = key;
	if (game->key == 123)
		game->left_arrow = 0;
	if (game->key == 124)
		game->right_arrow = 0;
	if (game->key == 0)
		game->press_a = 0;
	if (game->key == 2)
		game->press_d = 0;
	if (game->key == 1)
		game->press_s = 0;
	if (game->key == 13)
		game->press_w = 0;
	if (game->key == 49)
		game->press_shift = 0;
	return (1);
}
