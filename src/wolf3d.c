/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:59:57 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/08 18:15:51 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int				press_key(int key, t_mlx *mlx)
{
	if (key == 53)
		ft_exit(mlx);
	if ((key >= 0 && key <= 2) || key == 13)
		move_player(key, mlx);
	if (key == 124)
	{
		mlx->player.angle += 5 * M_PI / 180;
		wolf_init(mlx);
	}
	if (key == 123)
	{
		mlx->player.angle -= 5 * M_PI / 180;
		wolf_init(mlx);
	}
	if (key == 46)
	{
		if (mlx->minimap == 0)
			mlx->minimap = 1;
		else
			mlx->minimap = 0;
		wolf_init(mlx);
	}
	return (0);
}

static int				mouse_move(int x, int y, t_mlx *mlx)
{
	float		radpp;
	static int	i = 0;

	y = 0;
	if (i++ == 0)
		mlx->mouse.mouse_x = x;
	radpp = (60 * M_PI / 180) / mlx->x;
	if (x >= 0 && x <= 1000)
	{
		mlx->player.angle += (radpp * (x - mlx->mouse.mouse_x));
		wolf_init(mlx);
		if (mlx->anim > 0 && mlx->anim < 5)
			mlx->anim++;
	}
	mlx->mouse.mouse_x = x;
	return (0);
}

static int				mouse_press(int key, int x, int y, t_mlx *mlx)
{
	x = y;
	if (key == 1)
	{
		system("afplay sound/1.mp3 &");
		mlx->anim = 1;
		mlx->mouse.mouse_1 = 1;
	}
	return (0);
}

static int				mouse_release(int key, int x, int y, t_mlx *mlx)
{
	x = y;
	if (key == 1)
		mlx->mouse.mouse_1 = 0;
	return (0);
}

void					wolf3d(t_mlx *mlx)
{
	if (mlx->secret == 1)
	{
		mlx->mlx_ptr = mlx_init();
		mlx->x = 1000;
		mlx->y = 800;
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->x, mlx->y, "wolf3d");
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->x, mlx->y);
		mlx->img_data = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
			&mlx->size_line, &mlx->end);
	}
	player_init(mlx);
	wolf_init(mlx);
	mlx_hook(mlx->win_ptr, 17, 0, ft_exit, mlx);
	mlx_hook(mlx->win_ptr, 2, 0, press_key, mlx);
	mlx_hook(mlx->win_ptr, 4, 0, mouse_press, mlx);
	mlx_hook(mlx->win_ptr, 5, 0, mouse_release, mlx);
	mlx_hook(mlx->win_ptr, 6, 0, mouse_move, mlx);
	mlx_loop_hook(mlx->mlx_ptr, loop_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
}
