/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:52:04 by acharras          #+#    #+#             */
/*   Updated: 2020/03/02 13:37:26 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_calculate_draw(t_cub3d *game)
{
	game->lineheight = (int)(game->height / game->perspwalldist);
	game->drawstart = -game->lineheight / 2 + game->height / 2;
	if (game->drawstart < 0)
		game->drawstart = 0;
	game->drawend = game->lineheight / 2 + game->height / 2;
	if (game->drawend >= game->height)
		game->drawend = game->height - 1;
	game->movespeed = 0.06;
	game->rotspeed = 0.04;
}

static void	ft_check_collusion(t_cub3d *game)
{
	game->hit = 0;
	while (game->hit == 0)
	{
		if (game->sidedistx <= game->sidedisty)
		{
			game->sidedistx += game->deltadistx;
			game->mapx += game->stepx;
			game->side = 1;
		}
		else
		{
			game->sidedisty += game->deltadisty;
			game->mapy += game->stepy;
			game->side = 0;
		}
		if (game->map[game->mapy][game->mapx] == '1')
			game->hit = 1;
	}
}

static void	ft_init_map(t_cub3d *game)
{
	game->mapx = (int)game->posx;
	game->mapy = (int)game->posy;
	game->deltadistx = fabs(1 / game->raydirx);
	game->deltadisty = fabs(1 / game->raydiry);
	if (game->raydirx < 0)
	{
		game->stepx = -1;
		game->sidedistx = (game->posx - game->mapx) * game->deltadistx;
	}
	else
	{
		game->stepx = 1;
		game->sidedistx = (game->mapx + 1.0 - game->posx) * game->deltadistx;
	}
	if (game->raydiry < 0)
	{
		game->stepy = -1;
		game->sidedisty = (game->posy - game->mapy) * game->deltadisty;
	}
	else
	{
		game->stepy = 1;
		game->sidedisty = (game->mapy + 1.0 - game->posy) * game->deltadisty;
	}
}

static void	ft_raycasting_next(t_cub3d *game)
{
	int		i;

	i = 0;
	game->x = 0;
	while (game->x < game->sp_nbr)
	{
		ft_calculate_sprite(game, game->x);
		ft_draw_sprite(game, i);
		game->x++;
	}
	if (game->screenshot == 1)
	{
		ft_save_bitmap("bitmap.bmp", game);
		ft_exit(game);
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, 0, 0);
	mlx_hook(game->win_ptr, 2, 0, key_input, game);
	mlx_hook(game->win_ptr, 3, 0, key_release, game);
	mlx_hook(game->win_ptr, 17, 0, ft_close_prog, game);
}

void		ft_raycasting(t_cub3d *game)
{
	ft_draw_floor_ceiling(game);
	while (++game->x < game->width)
	{
		game->camerax = 2 * game->x / (double)game->width - 1;
		game->raydirx = game->dirx + game->planex * game->camerax;
		game->raydiry = game->diry + game->planey * game->camerax;
		ft_init_map(game);
		ft_check_collusion(game);
		if (game->side == 1)
			game->perspwalldist = (game->mapx - game->posx + (1 - game->stepx)
				/ 2) / game->raydirx;
		else
			game->perspwalldist = (game->mapy - game->posy + (1 - game->stepy)
				/ 2) / game->raydiry;
		ft_calculate_draw(game);
		ft_texture(game);
		while (game->drawstart <= game->drawend)
		{
			ft_draw(game);
			game->img_data[game->drawstart++ * game->width +
				game->x] = game->color;
		}
		game->zbuffer[game->x] = game->perspwalldist;
	}
	ft_raycasting_next(game);
}
