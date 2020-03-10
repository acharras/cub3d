/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_see.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:14:30 by acharras          #+#    #+#             */
/*   Updated: 2020/03/10 16:42:05 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_move_f_b(t_cub3d *game)
{
	if (game->press_w == 1)
	{
		game->posy += game->diry * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy -= game->diry * game->movespeed;
		game->posx += game->dirx * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx -= game->dirx * game->movespeed;
	}
	if (game->press_s == 1)
	{
		game->posy -= game->diry * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy += game->diry * game->movespeed;
		game->posx -= game->dirx * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx += game->dirx * game->movespeed;
	}
}

static void	ft_move_r_l(t_cub3d *game)
{
	if (game->press_a == 1)
	{
		game->posy -= game->planey * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy += game->planey * game->movespeed;
		game->posx -= game->planex * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx += game->planex * game->movespeed;
	}
	if (game->press_d == 1)
	{
		game->posy += game->planey * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posy -= game->planey * game->movespeed;
		game->posx += game->planex * game->movespeed;
		if (game->map[(int)(game->posy)][(int)(game->posx)] == '1' ||
			game->map[(int)(game->posy)][(int)(game->posx)] == '2')
			game->posx -= game->planex * game->movespeed;
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
	}
}

int			key_move(t_cub3d *game)
{
	game->movespeed = 0.06;
	game->rotspeed = 0.04;
	if (game->press_shift == 1)
		game->movespeed += 0.04;
	game->wait_life++;
	if (game->wait_life == 6)
		game->wait_life = 0;
	ft_move_f_b(game);
	ft_move_r_l(game);
	ft_see_r(game);
	ft_see_l(game);
	if (((game->map[(int)(game->posy + game->diry * game->movespeed)]
		[(int)(game->posx + game->dirx * game->movespeed)] == '2') ||
		(game->map[(int)(game->posy - game->diry * game->movespeed)]
		[(int)(game->posx - game->dirx * game->movespeed)] == '2') ||
		(game->map[(int)(game->posy - game->planey * game->movespeed)]
		[(int)(game->posx - game->planex * game->movespeed)] == '2') ||
		(game->map[(int)(game->posy + game->planey * game->movespeed)]
		[(int)(game->posx + game->planex * game->movespeed)] == '2')) &&
		game->wait_life == 5)
		game->life -= 15;
	if (game->life <= 0)
	{
		game->posy = game->map_starty;
		game->posx = game->map_startx;
		game->life = 100;
	}
	ft_raycasting(game);
	return (1);
}
