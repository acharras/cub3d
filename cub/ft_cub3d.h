/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acharras <acharras@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:38:23 by acharras          #+#    #+#             */
/*   Updated: 2020/03/10 16:39:05 by acharras         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct		s_bpm
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bpm;

typedef struct		s_bpm2
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bpm2;

typedef struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_sprites
{
	double		x;
	double		y;
}					t_sprites;

typedef	struct		s_cub3d
{
	int				check_space_nbr;
	int				tracked;
	void			*mlx_ptr;
	void			*win_ptr;
	int				right_c;
	int				left_c;
	int				scroll_c;
	int				scroll_up;
	int				scroll_do;
	int				height;
	int				width;
	char			*north;
	int				verif_no;
	char			*south;
	int				verif_so;
	char			*east;
	int				verif_ea;
	char			*west;
	int				verif_we;
	char			*sprite;
	int				verif_sp;
	char			key;
	char			**tab_color;
	int				color_floor;
	int				color_ceiling;
	char			**map;
	char			*tmp_map;
	int				newline_map;
	int				map_i;
	int				check_map;
	int				map_false;
	int				color;
	int				fd;
	char			*map_cub;
	char			dir_player;
	int				verif_c;
	int				verif_f;
	int				verif_r;
	int				hit;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			olddirx;
	double			olddiry;
	double			planex;
	double			planey;
	double			oldplanex;
	double			oldplaney;
	double			camerax;
	double			raydiry;
	double			raydirx;
	int				stepy;
	int				stepx;
	double			sidedistx;
	double			sidedisty;
	int				mapx;
	int				mapy;
	double			deltadistx;
	double			deltadisty;
	int				side;
	double			perspwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	int				left_arrow;
	int				right_arrow;
	int				press_a;
	int				press_d;
	int				press_s;
	int				press_w;
	int				press_shift;
	int				life;
	int				maxlife;
	int				x;
	int				bits_per_pixel;
	int				endian;
	int				size_line;
	int				tex_num;
	int				tex_x;
	int				tex_y;
	int				tex_pos;
	int				no_width;
	int				no_height;
	int				so_width;
	int				so_height;
	int				we_width;
	int				we_height;
	int				ea_width;
	int				ea_height;
	int				sp_width;
	int				sp_height;
	int				sp_w;
	int				sp_h;
	int				drawstartx;
	int				drawendx;
	int				drawstarty;
	int				drawendy;
	int				sp_screen;
	double			transx;
	double			transy;
	double			inv_det;
	double			sp_x;
	double			sp_y;
	int				sp_nbr;
	int				*sp_order;
	double			*sp_dist;
	size_t			calc;
	int				res_y;
	int				res_x;
	int				line_height;
	void			*img_ptr;
	void			*img_no_ptr;
	void			*img_so_ptr;
	void			*img_we_ptr;
	void			*img_ea_ptr;
	void			*sprite_ptr;
	int				*img_data;
	int				*data_no;
	int				*data_so;
	int				*data_we;
	int				*data_ea;
	int				*data_sprite;
	double			tex_width;
	double			tex_height;
	double			*zbuffer;
	double			wallx;
	double			texpos;
	double			step;
	int				screenshot;
	int				wait_life;
	int				map_startx;
	int				map_starty;
}					t_cub3d;

typedef union
{
	int				color;
	char			argb[4];
}					t_color;

void				ft_map(t_cub3d *game);
int					ft_check_map(t_cub3d *game, char *line);
int					ft_check_full_arg(t_cub3d *game, char *line);
void				ft_rm_space(t_cub3d *game);
void				ft_check_map_error(t_cub3d *game);
int					key_input(int key, t_cub3d *game);
void				ft_raycasting(t_cub3d *game);
int					key_move(t_cub3d *game);
int					key_release(int key, t_cub3d *game);
void				ft_texture(t_cub3d *game);
void				ft_draw_floor_ceiling(t_cub3d *game);
void				ft_draw(t_cub3d *game);
void				ft_draw_sprite(t_cub3d *game, int i);
void				ft_calculate_sprite(t_cub3d *game, int x);
void				ft_save_bitmap(char *filename, t_cub3d *game);
void				ft_init_game(t_cub3d *game);
void				ft_texture_init(t_cub3d *game);
void				ft_exit(t_cub3d *game);
void				ft_exit_texture(t_cub3d *game);
int					ft_close_prog(t_cub3d *game);
void				ft_check_arg(t_cub3d *game, char *line);
void				ft_colors(t_cub3d *game, char *line);
void				ft_path(t_cub3d *game, char *line);
void				ft_alloc_sprite_order(t_cub3d *game);
void				ft_check_space(t_cub3d *game, int i, int j);
void				ft_check_number(t_cub3d *game, char *line, int j);
void				ft_check_map_cub(t_cub3d *game, int error, int i, int j);
void				ft_draw_lifebar(t_cub3d *game);

#endif
