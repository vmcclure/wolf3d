/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:12:40 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/08 14:12:40 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		player_init(t_mlx *mlx)
{
	int x;
	int y;

	y = -1;
	while (mlx->map[++y] != 0)
	{
		x = -1;
		while (mlx->map[y][++x] != '\0')
			if (mlx->map[y][x] == 'p')
			{
				mlx->player.x = (x + 0.5) * SIZE;
				mlx->player.y = (y + 0.5) * SIZE;
			}
	}
	mlx->anim = 0;
	mlx->player.angle = 0.0;
	mlx->mouse.mouse_1 = 0;
	mlx->mouse.mouse_2 = 0;
	mlx->mouse.mouse_x = 0;
	mlx->mouse.mouse_y = 0;
	mlx->minimap = 0;
}
