/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_second.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:27:52 by acharras          #+#    #+#             */
/*   Updated: 2020/03/12 14:10:17 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void	ft_draw_sprintbar(t_cub3d *game)
{
	int		x;
	int		y;

	x = game->width / 20;
	while (x < game->width / 5)
	{
		y = game->height / 18;
		while (y < game->height / 14)
		{
			if (game->sprint != 0 && (x >
			(int)((double)(game->width / 5) * (1 -
			(double)game->sprint / (double)game->maxsprint))))
				game->img_data[y * game->width + x] = 0x0000ff;
			else if (x < game->width - game->width / 20)
				game->img_data[y * game->width + x] = 0x000000;
			y++;
		}
		x++;
	}
}

void	ft_check_life(t_cub3d *game)
{
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
}

void	ft_draw_lifebar(t_cub3d *game)
{
	int		x;
	int		y;

	x = game->width / 20;
	while (x < game->width / 5)
	{
		y = game->height / 30;
		while (y < game->height / 20)
		{
			if (game->life != 0 && (x >
			(int)((double)(game->width / 5) * (1 -
			(double)game->life / (double)game->maxlife))))
				game->img_data[y * game->width + x] = 0xff0000;
			else if (x < game->width - game->width / 20)
				game->img_data[y * game->width + x] = 0x000000;
			y++;
		}
		x++;
	}
}
