/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:39:33 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/07 22:35:29 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static float	ft_hvost(float res)
{
	return (res - (int)res);
}

static void		side_init(t_thredsct *sct, t_valdist val)
{
	if (sin(sct->mlx->player.angle + val.start_rad +
	(sct->startx * val.radpp)) < 0)
		sct->mlx->rays[sct->startx].ns = 'S';
	else
		sct->mlx->rays[sct->startx].ns = 'N';
	if (cos(sct->mlx->player.angle + val.start_rad +
	(sct->startx * val.radpp)) < 0)
		sct->mlx->rays[sct->startx].we = 'E';
	else
		sct->mlx->rays[sct->startx].we = 'W';
}

static void		main_while(t_thredsct *sct, t_valdist *val)
{
	while (sct->mlx->map[(int)val->y_map / SIZE]
				[(int)val->x_map / SIZE] == ' ' ||
				sct->mlx->map[(int)val->y_map / SIZE]
				[(int)val->x_map / SIZE] == 'p')
	{
		val->step += 0.1;
		val->x_map = sct->mlx->player.x + val->step *
				cos(sct->mlx->player.angle + val->start_rad +
				(sct->startx * val->radpp));
		if (sct->mlx->map[(int)val->y_map / SIZE][(int)val->x_map / SIZE] == '1'
		|| sct->mlx->map[(int)val->y_map / SIZE][(int)val->x_map / SIZE] == 's')
			sct->mlx->rays[sct->startx].ns = 0;
		if (sct->mlx->rays[sct->startx].ns != 0)
		{
			val->y_map = sct->mlx->player.y + val->step *
					sin(sct->mlx->player.angle + val->start_rad
					+ (sct->startx * val->radpp));
			if (sct->mlx->map[(int)val->y_map / SIZE][(int)val->x_map / SIZE]
			== '1' || sct->mlx->map[(int)val->y_map / SIZE][(int)val->x_map /
			SIZE] == 's')
				sct->mlx->rays[sct->startx].we = 0;
		}
	}
}

static void		height_vertical(t_thredsct *sct, t_valdist val)
{
	if (sct->mlx->rays[sct->startx].we == 0)
		sct->mlx->rays[sct->startx].vertical =
				ft_hvost(val.x_map / SIZE) * (SIZE);
	else if (sct->mlx->rays[sct->startx].ns == 0)
		sct->mlx->rays[sct->startx].vertical =
				ft_hvost(val.y_map / SIZE) * (SIZE);
	sct->mlx->rays[sct->startx].height =
			sct->mlx->y / ((val.step * cos(val.start_rad +
			(sct->startx * val.radpp))) * 0.01);
}

void			*distance_init(t_thredsct *sct)
{
	t_valdist	val;

	val.start_rad = -(30 * M_PI / 180);
	val.radpp = (60 * M_PI / 180) / sct->mlx->x;
	while (++sct->startx < sct->maxx)
	{
		val.step = 0;
		val.x_map = sct->mlx->player.x + val.step *
				cos(sct->mlx->player.angle + val.start_rad
				+ (sct->startx * val.radpp));
		val.y_map = sct->mlx->player.y + val.step *
				sin(sct->mlx->player.angle + val.start_rad
				+ (sct->startx * val.radpp));
		side_init(sct, val);
		main_while(sct, &val);
		height_vertical(sct, val);
	}
	return (0);
}
