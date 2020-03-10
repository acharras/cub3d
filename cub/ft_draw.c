/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:52:32 by acharras          #+#    #+#             */
/*   Updated: 2020/03/10 16:36:39 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

void		ft_draw(t_cub3d *game)
{
	if (game->side == 0)
		game->tex_y = game->stepy > 0 ? ((int)game->texpos &
			game->no_height - 1) :
		((int)game->texpos & game->so_height - 1);
	else if (game->side == 1)
		game->tex_y = game->stepx < 0 ? ((int)game->texpos &
			game->ea_height - 1) :
		((int)game->texpos & game->we_height - 1);
	if (game->side == 0)
		game->color = game->stepy > 0 ? game->data_no[game->no_height
			* game->tex_y + game->tex_x] :
			game->data_so[game->so_height * game->tex_y + game->tex_x];
	else if (game->side == 1)
	{
		if (game->ea_height * game->tex_y + game->tex_x <
			game->ea_height * game->ea_width)
		{
			game->color = game->stepx < 0 ?
				game->data_ea[game->ea_height * game->tex_y +
			game->tex_x] : game->data_we[game->we_height * game->tex_y
			+ game->tex_x];
		}
	}
	game->texpos += game->step;
}

void		ft_draw_floor_ceiling(t_cub3d *game)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	game->x = -1;
	while (++j < game->height / 2)
	{
		i = -1;
		while (++i < game->width)
			game->img_data[j * game->width + i] = game->color_ceiling;
	}
	while (j < game->height)
	{
		i = -1;
		while (++i < game->width)
			game->img_data[j * game->width + i] = game->color_floor;
		j++;
	}
}

static void	ft_draw_sprite_next(t_cub3d *game)
{
	game->tex_y = (int)((game->calc * game->sp_height) / game->sp_h) / 256;
	if (game->tex_x < 0)
		game->tex_x = 0;
	if (game->tex_y < 0)
		game->tex_y = 0;
	if (game->sp_width * game->tex_y + game->tex_x < game->sp_width *
		game->sp_height)
		game->color = game->data_sprite[game->sp_width *
			game->tex_y + game->tex_x];
}

void		ft_draw_sprite(t_cub3d *game, int i)
{
	while (game->drawstartx < game->drawendx && game->drawstartx < game->width)
	{
		i = game->drawstarty;
		game->tex_x = (int)(256 * (game->drawstartx - (-game->sp_w / 2
			+ game->sp_screen)) * game->sp_width / game->sp_w) / 256;
		if (game->tex_x < 0)
			game->tex_x = 0;
		if (game->tex_y < 0)
			game->tex_y = 0;
		if (game->drawstartx < game->width && game->transy > 0 &&
		game->drawstartx > 0 && game->transy < game->zbuffer[game->drawstartx])
		{
			while (++i < game->drawendy && i < game->height)
			{
				game->calc = i * 256 - game->height * 128 + game->sp_h * 128;
				ft_draw_sprite_next(game);
				if ((game->color & 0xffffff) != 0 && game->width *
					game->height > i * game->width + game->drawstartx)
					game->img_data[i * game->width +
						game->drawstartx] = game->color;
			}
		}
		game->drawstartx++;
	}
}

void	ft_draw_lifebar(t_cub3d *game)
{
	int		x;
	int		y;

	x = game->width / 20;
	while (x < game->width - game->width / 20)
	{
		y = game->height - game->height / 20;
		while (y < game->height)
		{
			if ((game->life != 0 && x > game->width / 17 &&
			x < game->width - game->width / 17) && (x >
			(int)((double)(game->width - game->width / 20) * (1 -
			(double)game->life / (double)game->maxlife))))
				game->img_data[y * game->width + x] = 0xff0000;
			else if (x < game->width - game->width / 20)
				game->img_data[y * game->width + x] = 0x000000;
			y++;
		}
		x++;
	}
}
