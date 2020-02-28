/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 13:00:49 by acharras          #+#    #+#             */
/*   Updated: 2020/02/28 18:29:06 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_fov_init_next(t_cub3d *game)
{
	if (game->dir_player == 'E')
	{
		game->dirx = 1.0;
		game->diry = 0.0;
		game->planex = 0.0;
		game->planey = 0.66;
	}
	if (game->dir_player == 'W')
	{
		game->dirx = -1.0;
		game->diry = 0.0;
		game->planex = 0.0;
		game->planey = -0.66;
	}
}

static void	ft_fov_init(t_cub3d *game)
{
	if (game->dir_player == 'N')
	{
		game->dirx = 0.0;
		game->diry = -1.0;
		game->planex = 0.66;
		game->planey = 0.0;
	}
	if (game->dir_player == 'S')
	{
		game->dirx = 0.0;
		game->diry = 1.0;
		game->planex = -0.66;
		game->planey = 0.0;
	}
	ft_fov_init_next(game);
	game->posx += 0.5;
	game->posy += 0.5;
}

static int	ft_check_screenshot(t_cub3d *game, int ac, char **ag)
{
	if (ac == 3)
	{
		if (ft_strncmp(ag[2], "--save", 6) == 0)
			game->screenshot = 1;
		else
		{
			ft_putstr("Error\nThird argument is false only '--save'");
			ft_putstr(" is allowed\n");
			exit(0);
		}
	}
	return (1);
}

static void	ft_check_args(t_cub3d *game, int ac, char **av)
{
	if (ac > 3)
	{
		ft_putstr("Error\nToo much arguments\n");
		exit(0);
	}
	if (ac < 2)
	{
		ft_putstr("Error\nToo few arguments\n");
		exit(0);
	}
	game->map_cub = av[1];
	ft_check_screenshot(game, ac, av);
}

int			main(int ac, char **av)
{
	t_cub3d		game[1];

	ft_check_args(game, ac, av);
	ft_init_game(game);
	ft_map(game);
	ft_fov_init(game);
	if ((game->mlx_ptr = mlx_init()) == NULL)
		ft_exit(game);
	if ((game->win_ptr = mlx_new_window(game->mlx_ptr, game->width,
			game->height, "Cub3D")) == NULL)
		ft_exit(game);
	game->tracked = 1;
	ft_texture_init(game);
	if (!(game->zbuffer = malloc(sizeof(double) * game->width)))
		ft_exit(game);
	ft_raycasting(game);
	mlx_loop_hook(game->mlx_ptr, key_move, (void *)game);
	mlx_loop(game->mlx_ptr);
	ft_exit(game);
	return (EXIT_SUCCESS);
}
