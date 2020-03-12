/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:41:57 by acharras          #+#    #+#             */
/*   Updated: 2020/03/12 13:10:58 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_exit_next(t_cub3d *game)
{
	int i;

	i = -1;
	ft_memdel((void *)&(game->sp_order));
	ft_memdel((void *)&(game->sp_dist));
	ft_memdel((void *)&(game->east));
	ft_memdel((void *)&(game->north));
	ft_memdel((void *)&(game->south));
	ft_memdel((void *)&(game->west));
	ft_memdel((void *)&(game->sprite));
	if (game->tracked > 7)
		ft_memdel((void *)&(game->zbuffer));
	ft_memdel((void*)&game->tmp_map);
	if (game->tab_color != NULL)
		while (game->tab_color[++i])
			ft_memdel((void*)&game->tab_color[i]);
	ft_memdel((void *)&(game->tab_color));
	i = -1;
	if (game->map != NULL)
		while (game->map[++i])
			ft_memdel((void*)&game->map[i]);
	ft_memdel((void*)&game->map);
}

void		ft_exit_texture(t_cub3d *game)
{
	if (game->tracked > 0)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->tracked > 1)
	{
		ft_putstr("Error\nIncorrect texture path...\n");
		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
		if (game->tracked > 2 && game->img_no_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_no_ptr);
		if (game->tracked > 3 && game->img_so_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_so_ptr);
		if (game->tracked > 4 && game->img_ea_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_ea_ptr);
		if (game->tracked > 5 && game->img_we_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_we_ptr);
		if (game->tracked > 6 && game->sprite_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->sprite_ptr);
	}
	ft_exit_next(game);
	exit(1);
}

void		ft_exit(t_cub3d *game)
{
	if (game->tracked > 0 && game->img_ptr != 0)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->tracked > 1)
	{
		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
		if (game->tracked > 2 && game->img_no_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_no_ptr);
		if (game->tracked > 3 && game->img_so_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_so_ptr);
		if (game->tracked > 4 && game->img_ea_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_ea_ptr);
		if (game->tracked > 5 && game->img_we_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->img_we_ptr);
		if (game->tracked > 6 && game->sprite_ptr != 0)
			mlx_destroy_image(game->mlx_ptr, game->sprite_ptr);
	}
	ft_exit_next(game);
	exit(1);
}

int			ft_close_prog(t_cub3d *game)
{
	ft_exit(game);
	return (0);
}
