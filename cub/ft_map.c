/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 12:52:46 by acharras          #+#    #+#             */
/*   Updated: 2020/03/06 14:32:37 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_read_map(t_cub3d *game, int ret, char *line)
{
	while ((ret = get_next_line(game->fd, &line) > 0))
	{
		ft_check_arg(game, line);
		if (!(ft_check_map(game, line)))
			ft_exit(game);
		ft_memdel((void*)&line);
	}
	if (ft_check_full_arg(game, line) == 1 && game->check_map >= 2)
	{
		if (!(game->tmp_map = ft_strjoin_f_s1(game->tmp_map, line)))
			ft_exit(game);
		if (!(game->tmp_map = ft_strjoin_f_s1(game->tmp_map, "\n")))
			ft_exit(game);
		game->map_i++;
	}
	if (ft_check_full_arg(game, line) == 0)
	{
		ft_putstr("Error\nBad argument...\n");
		ft_exit(game);
	}
	ft_memdel((void*)&line);
}

void		ft_map(t_cub3d *game)
{
	int		ret;
	int		i;
	char	*line;

	i = 0;
	game->fd = open(game->map_cub, O_RDONLY);
	ret = 0;
	line = NULL;
	if (!(game->tmp_map = ft_strdup("")))
		ft_exit(game);
	ft_read_map(game, ret, line);
	if (!(game->map = ft_split(game->tmp_map, '\n')))
		ft_exit(game);
	ft_memdel((void*)&line);
	close(game->fd);
	ft_check_map_error(game);
	game->map[(int)game->posy][(int)game->posx] = '0';
}
