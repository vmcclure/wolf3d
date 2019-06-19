/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:18:26 by dtreutel          #+#    #+#             */
/*   Updated: 2019/03/26 15:48:07 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	clear_image(t_mlx *mlx)
{
	int	y;
	int x;

	y = -1;
	while (++y < mlx->y)
	{
		x = -1;
		while (++x < mlx->x)
		{
			set_pxl(mlx->img_data, x * 4,
					y * mlx->size_line, 0);
		}
	}
}
