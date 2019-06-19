/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:54:55 by vmcclure          #+#    #+#             */
/*   Updated: 2019/04/08 13:56:41 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	void	steni_player(int player, int i, t_mlx *mlx)
{
	mlx->img_data[i] = (char)255;
	mlx->img_data[i + 1] = (char)255;
	mlx->img_data[i + 2] = (char)255;
	mlx->img_data[player] = (char)10;
	mlx->img_data[player + 1] = (char)10;
	mlx->img_data[player + 2] = (char)255;
}

static void		ft_koroche(t_mlx *mlx, int i)
{
	mlx->img_data[i] = (char)255;
	mlx->img_data[i + 1] = (char)0;
	mlx->img_data[i + 2] = (char)0;
}

static void		zlivka(t_mlx *mlx, int x, int y, int y1)
{
	int			x1;
	int			i;
	int			player;

	x1 = 0;
	while (x1 < 10)
	{
		player = (mlx->player.y / SIZE * 10 + y1) * mlx->size_line
			+ (mlx->player.x / SIZE * 10 + x1) * 4;
		i = (y * 10 + y1) * mlx->size_line + (x * 10 + x1) * 4;
		if (i > 1000000)
			return ;
		if (mlx->map[y][x] == '1')
			steni_player(player, i, mlx);
		else
		{
			mlx->img_data[i] = (char)0;
			mlx->img_data[i + 1] = (char)0;
			mlx->img_data[i + 2] = (char)0;
		}
		if (mlx->map[y][x] == 's')
			ft_koroche(mlx, i);
		x1++;
	}
}

void			minimap(t_mlx *mlx)
{
	int			x;
	int			y;
	int			y1;

	if (mlx->minimap == 0)
		return ;
	y = 0;
	x = 0;
	while (mlx->map[y] != 0)
	{
		x = 0;
		while (mlx->map[y][x] != '\0')
		{
			y1 = 0;
			while (y1 < 10)
			{
				zlivka(mlx, x, y, y1);
				y1++;
			}
			x++;
		}
		y++;
	}
}
