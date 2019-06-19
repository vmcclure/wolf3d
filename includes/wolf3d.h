/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:54:35 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/08 14:06:26 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# define BUFF_SIZE 111
# define SIZE 64

typedef struct		s_line
{
	int				x0;
	int				y0;
	int				clr0;
	int				x1;
	int				y1;
	int				clr1;
}					t_line;

typedef struct		s_val
{
	int				deltax;
	int				deltay;
	int				signx;
	int				signy;
	int				error;
	int				error2;
}					t_val;

typedef struct		s_player
{
	int				x;
	int				y;
	float			angle;
}					t_player;

typedef struct		s_mouse
{
	int				mouse_1;
	int				mouse_2;
	int				mouse_x;
	int				mouse_y;
}					t_mouse;

typedef struct		s_ray
{
	char			we;
	char			ns;
	int				vertical;
	int				height;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				size_line;
	int				end;
	int				x;
	int				y;
	int				anim;
	int				secret;
	char			**map;
	int				minimap;
	t_player		player;
	t_mouse			mouse;
	t_ray			rays[1000];
}					t_mlx;

typedef struct		s_valdist
{
	float			start_rad;
	float			radpp;
	float			x_map;
	float			y_map;
	float			step;
}					t_valdist;

typedef struct		s_thredsct
{
	int				startx;
	int				maxx;
	t_mlx			*mlx;
}					t_thredsct;

typedef struct		s_bmpheader
{
	unsigned char	b1;
	unsigned char	b2;
	unsigned short	bfsize;
	unsigned short	bfreserved1;
	unsigned short	bfreserved2;
	unsigned short	padding;
	unsigned short	bfoffbits;
	char			a[42];
}					t_bmphead;

typedef struct		s_texture
{
	int				fail;
	int				width;
	int				height;
	unsigned char	*pixels;
	int				bpp;
	t_bmphead		hdbmp;
}					t_texture;

int					ft_exit(t_mlx *mlx);
int					get_next_line(const int fd, char **line);
int					get_map(int fd, char ***map);
int					loop_hook(t_mlx *mlx);
void				player_init(t_mlx *mlx);
void				put_textur(t_mlx *mlx);
void				move_player(int key, t_mlx *mlx);
void				clear_image(t_mlx *mlx);
void				wolf_init(t_mlx *mlx);
void				wolf3d(t_mlx *mlx);
void				put_line(t_mlx *mlx, t_line line);
void				set_pxl(char *str, int x, int y, int clr);
void				*distance_init(t_thredsct *sct);
void				minimap(t_mlx *mlx);
void				put_pistol(t_mlx *mlx);
t_texture			readbmp(char *filename);

#endif
