/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 09:36:04 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/07 22:32:27 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		comnata(t_mlx *mlx)
{
	int			fd;

	ft_arraydel((void **)mlx->map);
	free(mlx->map);
	if (get_map(fd = open("maps/map2", O_RDONLY), &mlx->map) <= 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
	close(fd);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->secret = 2;
	wolf3d(mlx);
}

static void		floor_ceiling(t_mlx *mlx)
{
	int	y;
	int x;

	y = -1;
	while (++y < mlx->y / 2)
	{
		x = -1;
		while (++x < mlx->x)
		{
			set_pxl(mlx->img_data, x * 4,
					y * mlx->size_line, 0x61c3ff);
		}
	}
	y = mlx->y / 2;
	while (++y < mlx->y)
	{
		x = -1;
		while (++x < mlx->x)
		{
			set_pxl(mlx->img_data, x * 4,
					y * mlx->size_line, 0x808080);
		}
	}
}

void			wolf_init(t_mlx *mlx)
{
	pthread_t	threads[10];
	t_thredsct	sct[10];
	int			i;

	clear_image(mlx);
	floor_ceiling(mlx);
	i = -1;
	while (++i < 10)
	{
		sct[i].mlx = mlx;
		sct[i].startx = -1 + 100 * i;
		sct[i].maxx = sct[i].startx + 101;
		pthread_create(&threads[i], 0, (void *)distance_init,
				(void *)&sct[i]);
	}
	i = -1;
	while (++i < 10)
		pthread_join(threads[i], 0);
	put_textur(mlx);
	put_pistol(mlx);
	minimap(mlx);
	if (mlx->map[mlx->player.y / SIZE][mlx->player.x / SIZE] == 's')
		comnata(mlx);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
