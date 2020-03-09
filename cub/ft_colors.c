/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:45:51 by acharras          #+#    #+#             */
/*   Updated: 2020/03/09 12:27:03 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_init_colors(t_cub3d *game, t_color color, char *line)
{
	color.argb[0] = ft_atoi(game->tab_color[1]);
	color.argb[1] = ft_atoi(game->tab_color[2]);
	color.argb[2] = ft_atoi(game->tab_color[0]);
	if (line[0] == 'F')
	{
		game->color_floor = color.color;
		game->verif_f++;
	}
	if (line[0] == 'C')
	{
		game->color_ceiling = color.color;
		game->verif_c++;
	}
}

static void	ft_error_colors(t_cub3d *game)
{
	if (game->tab_color[0] == NULL || game->tab_color[1] == NULL ||
		game->tab_color[2] == NULL || game->tab_color[3] != NULL)
	{
		ft_putstr("Error\nArgument | F | C | had a bad format...\n");
		ft_exit(game);
	}
	if (0 > ft_atoi(game->tab_color[0]) || ft_atoi(game->tab_color[0]) > 255
			|| 0 > ft_atoi(game->tab_color[1]) || ft_atoi(game->tab_color[1])
				> 255 || 0 > ft_atoi(game->tab_color[2]) ||
					ft_atoi(game->tab_color[2]) > 255)
	{
		ft_putstr("Error\nColor error...\n");
		ft_exit(game);
	}
}

static void	ft_check_path_colors(t_cub3d *game, char *line, int j)
{
	if (line[j] == '.')
	{
		ft_putstr("Error\nArgument | F | C | cannot save texture path...\n");
		ft_exit(game);
	}
	if (!(game->tab_color = ft_split(&line[j], ',')))
		ft_exit(game);
	while (line[j] != '\0' && line[j] == ' ')
		j++;
	ft_check_number(game, line, j);
	while (line[j] != '\0')
	{
		if (line[j] != '0' && line[j] != '1' && line[j] != '2' &&
			line[j] != '3' && line[j] != '4' && line[j] != '5' &&
			line[j] != '6' && line[j] != '7' && line[j] != '8' &&
			line[j] != '9' && line[j] != ',' && line[j] != ' ')
		{
			ft_putstr("Error\nArgument | F | C | had a bad format...\n");
			ft_exit(game);
		}
		j++;
	}
}

static void	ft_check_comma(t_cub3d *game, char *line, int j)
{
	int comma;

	comma = 0;
	while (line[j] != '\0')
	{
		if (line[j] == ',')
			comma++;
		j++;
	}
	if (comma != 2)
	{
		ft_putstr("Error\nArgument | F | C | had a bad format...\n");
		ft_exit(game);
	}
}

void		ft_colors(t_cub3d *game, char *line)
{
	t_color	color;
	int		j;

	j = 1;
	color.argb[3] = 0;
	if (line[0] == 'F' || line[0] == 'C')
	{
		ft_check_comma(game, line, j);
		while (line[j] == ' ')
			j++;
		ft_check_path_colors(game, line, j);
		ft_error_colors(game);
		ft_init_colors(game, color, line);
		j = -1;
		while (game->tab_color[++j])
			ft_memdel((void*)&game->tab_color[j]);
		ft_memdel((void *)&(game->tab_color));
	}
	if (game->verif_f > 1 || game->verif_c > 1)
	{
		ft_putstr("Error\nToo many argument | F | C |...\n");
		ft_exit(game);
	}
}
