/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:04:50 by acharras          #+#    #+#             */
/*   Updated: 2020/02/26 15:11:55 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub3d.h"

static void	ft_bitmap_image(t_cub3d *game, int fd, t_bpm2 bitinf)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bitinf, sizeof(bitinf));
	y = game->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < game->width)
		{
			ble = game->img_data[y * game->width + x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
	close(fd);
}

void		ft_save_bitmap(char *filename, t_cub3d *game)
{
	int		fd;
	t_bpm	bitheader;
	t_bpm2	bitinf;

	ft_memcpy(&bitheader.bitmap_type, "BM", 2);
	bitheader.file_size = game->width * game->height * 4 + 54;
	bitheader.reserved1 = 0;
	bitheader.reserved2 = 0;
	bitheader.offset_bits = 0;
	bitinf.size_header = sizeof(bitinf);
	bitinf.width = game->width;
	bitinf.height = game->height;
	bitinf.planes = 1;
	bitinf.bit_count = 24;
	bitinf.compression = 0;
	bitinf.image_size = game->width * game->height * 4 + 54;
	bitinf.ppm_x = 2;
	bitinf.ppm_y = 2;
	bitinf.clr_used = 0;
	bitinf.clr_important = 0;
	fd = open(filename, O_RDONLY | O_CREAT, S_IRWXU);
	close(fd);
	fd = open(filename, O_RDWR);
	write(fd, &bitheader, 14);
	ft_bitmap_image(game, fd, bitinf);
}
