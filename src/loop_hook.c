/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:01:16 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/08 14:01:16 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		loop_hook(t_mlx *mlx)
{
	float radpp;

	radpp = (50 * M_PI / 180) / mlx->x;
	if (mlx->mouse.mouse_x < 0)
	{
		mlx->player.angle -= radpp * 50;
		wolf_init(mlx);
		if (mlx->anim > 0 && mlx->anim < 5)
			mlx->anim++;
	}
	if (mlx->mouse.mouse_x > 999)
	{
		mlx->player.angle += radpp * 50;
		wolf_init(mlx);
		if (mlx->anim > 0 && mlx->anim < 5)
			mlx->anim++;
	}
	if (mlx->anim != 0)
	{
		wolf_init(mlx);
		if (mlx->anim > 0 && mlx->anim < 5)
			mlx->anim++;
	}
	return (0);
}
