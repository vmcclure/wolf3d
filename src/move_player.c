/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:05:26 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/07 21:57:22 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	move_left(t_mlx *mlx)
{
	int x;
	int y;

	x = mlx->player.x + 16 * cos(mlx->player.angle - (90 * M_PI / 180));
	y = mlx->player.y + 16 * sin(mlx->player.angle - (90 * M_PI / 180));
	if ((mlx->map[(y + 1) / SIZE][(x + 1) / SIZE] == ' ' ||
		mlx->map[(y + 1) / SIZE][(x + 1) / SIZE] == 'p') &&
		(mlx->map[(y - 1) / SIZE][(x - 1) / SIZE] == ' ' ||
		mlx->map[(y - 1) / SIZE][(x - 1) / SIZE] == 'p'))
	{
		mlx->player.x = x;
		mlx->player.y = y;
	}
}

static void	move_back(t_mlx *mlx)
{
	int x;
	int y;

	x = mlx->player.x + 16 * cos(mlx->player.angle - (180 * M_PI / 180));
	y = mlx->player.y + 16 * sin(mlx->player.angle - (180 * M_PI / 180));
	if ((mlx->map[(y + 1) / SIZE][(x + 1) / SIZE] == ' ' ||
		mlx->map[(y + 1) / SIZE][(x + 1) / SIZE] == 'p') &&
		(mlx->map[(y - 1) / SIZE][(x - 1) / SIZE] == ' ' ||
		mlx->map[(y - 1) / SIZE][(x - 1) / SIZE] == 'p'))
	{
		mlx->player.x = x;
		mlx->player.y = y;
	}
}

static void	move_ahead(t_mlx *mlx)
{
	int x;
	int y;

	x = mlx->player.x + 16 * cos(mlx->player.angle);
	y = mlx->player.y + 16 * sin(mlx->player.angle);
	if ((mlx->map[(y + 1) / SIZE][(x + 1) / SIZE] == ' ' ||
		mlx->map[(y + 1) / SIZE][(x + 1) / SIZE] == 'p') &&
		(mlx->map[(y - 1) / SIZE][(x - 1) / SIZE] == ' ' ||
		mlx->map[(y - 1) / SIZE][(x - 1) / SIZE] == 'p'))
	{
		mlx->player.x = x;
		mlx->player.y = y;
	}
}

static void	move_right(t_mlx *mlx)
{
	int x;
	int y;

	x = mlx->player.x + 16 * cos(mlx->player.angle + (90 * M_PI / 180));
	y = mlx->player.y + 16 * sin(mlx->player.angle + (90 * M_PI / 180));
	if ((mlx->map[(y + 1) / SIZE][(x + 1) / SIZE] == ' ' ||
		mlx->map[(y + 1) / SIZE][(x + 1) / SIZE] == 'p' ||
		mlx->map[(y + 1) / SIZE][(x + 1) / SIZE] == 's') &&
		(mlx->map[(y - 1) / SIZE][(x - 1) / SIZE] == ' ' ||
		mlx->map[(y - 1) / SIZE][(x - 1) / SIZE] == 'p' ||
		mlx->map[(y - 1) / SIZE][(x - 1) / SIZE] == 's'))
	{
		mlx->player.x = x;
		mlx->player.y = y;
	}
}

void		move_player(int key, t_mlx *mlx)
{
	if (key == 0)
		move_left(mlx);
	if (key == 1)
		move_back(mlx);
	if (key == 13)
		move_ahead(mlx);
	if (key == 2)
		move_right(mlx);
	wolf_init(mlx);
	if (mlx->anim > 0 && mlx->anim < 5)
		mlx->anim++;
}
