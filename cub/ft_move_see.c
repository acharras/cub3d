/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_see.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:14:30 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 15:26:11 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_move_f_b(t_cub3d *game)
{
	if (game->press_w == 1)
	{
		if (game->map[(int)(game->posy + (game->diry * game->movespeed))]
				[(int)(game->posx + (game->dirx * game->movespeed))] == '0')
		{
			game->posx += game->dirx * game->movespeed;
			game->posy += game->diry * game->movespeed;
		}
		ft_raycasting(game);
	}
	if (game->press_s == 1)
	{
		if (game->map[(int)(game->posy - (game->diry * game->movespeed))]
				[(int)(game->posx - (game->dirx * game->movespeed))] == '0')
		{
			game->posx -= game->dirx * game->movespeed;
			game->posy -= game->diry * game->movespeed;
		}
		ft_raycasting(game);
	}
}

static void	ft_move_r_l(t_cub3d *game)
{
	if (game->press_a == 1)
	{
		if (game->map[(int)(game->posy - (game->planey * game->movespeed))]
				[(int)(game->posx - (game->planex * game->movespeed))] == '0')
		{
			game->posy -= game->planey * game->movespeed;
			game->posx -= game->planex * game->movespeed;
		}
		ft_raycasting(game);
	}
	if (game->press_d == 1)
	{
		if (game->map[(int)(game->posy + (game->planey * game->movespeed))]
				[(int)(game->posx + (game->planex * game->movespeed))] == '0')
		{
			game->posy += game->planey * game->movespeed;
			game->posx += game->planex * game->movespeed;
		}
		ft_raycasting(game);
	}
}

static void	ft_see_l(t_cub3d *game)
{
	if (game->left_arrow == 1)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(-game->rotspeed) -
			game->diry * sin(-game->rotspeed);
		game->diry = game->olddirx * sin(-game->rotspeed) +
			game->diry * cos(-game->rotspeed);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(-game->rotspeed) -
			game->planey * sin(-game->rotspeed);
		game->planey = game->oldplanex * sin(-game->rotspeed) +
			game->planey * cos(-game->rotspeed);
		ft_raycasting(game);
	}
}

static void	ft_see_r(t_cub3d *game)
{
	if (game->right_arrow == 1)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(game->rotspeed) - game->diry
			* sin(game->rotspeed);
		game->diry = game->olddirx * sin(game->rotspeed) +
			game->diry * cos(game->rotspeed);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(game->rotspeed) -
			game->planey * sin(game->rotspeed);
		game->planey = game->oldplanex * sin(game->rotspeed) +
			game->planey * cos(game->rotspeed);
		ft_raycasting(game);
	}
}

int			key_move(t_cub3d *game)
{
	ft_move_f_b(game);
	ft_move_r_l(game);
	ft_see_r(game);
	ft_see_l(game);
	return (1);
}
