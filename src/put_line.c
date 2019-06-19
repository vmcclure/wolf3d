/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 14:29:49 by dtreutel          #+#    #+#             */
/*   Updated: 2019/02/20 17:34:58 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		ft_abs(int a, int b)
{
	int	res;

	res = a - b;
	if (res < 0)
		res *= -1;
	return (res);
}

static void		left_start_line(t_line *line)
{
	int	c;

	if (line->x0 > line->x1)
	{
		c = line->x0;
		line->x0 = line->x1;
		line->x1 = c;
		c = line->y0;
		line->y0 = line->y1;
		line->y1 = c;
		c = line->clr0;
		line->clr0 = line->clr1;
		line->clr1 = c;
	}
}

static int		gradient(t_val *values, int clr0, int clr1, int i)
{
	float	r;
	float	g;
	float	b;
	int		maxdelta;

	maxdelta = values->deltax >= values->deltay ?
			values->deltax : values->deltay;
	b = clr0 % 256;
	g = (clr0 / 256) % 256;
	r = ((clr0 / 256) / 256);
	b = (b - (clr1 % 256)) / maxdelta * i;
	g = (g - ((clr1 / 256) % 256)) / maxdelta * i;
	r = (r - ((clr1 / 256) / 256)) / maxdelta * i;
	b = (clr0 % 256) - b;
	g = ((clr0 / 256) % 256) - g;
	r = (((clr0 / 256) / 256)) - r;
	return (((int)r * 256 + (int)g) * 256 + (int)b);
}

static void		koroche(t_mlx *mlx, t_line *line, t_val *values)
{
	if (line->x0 >= 0 && line->y0 >= 0)
		set_pxl(mlx->img_data, line->x0 * 4,
			line->y0 * mlx->size_line, line->clr0);
	values->error2 = values->error * 2;
	if (values->error2 > values->deltay * -1)
	{
		values->error -= values->deltay;
		line->x0 += values->signx;
	}
	if (values->error2 < values->deltax)
	{
		values->error += values->deltax;
		line->y0 += values->signy;
	}
}

void			put_line(t_mlx *mlx, t_line line)
{
	t_val	values;
	int		clr0;
	int		clr1;
	int		i;

	i = 0;
	left_start_line(&line);
	clr0 = line.clr0;
	clr1 = line.clr1;
	values.deltax = ft_abs(line.x1, line.x0);
	values.deltay = ft_abs(line.y1, line.y0);
	values.signx = line.x0 < line.x1 ? 1 : -1;
	values.signy = line.y0 < line.y1 ? 1 : -1;
	values.error = values.deltax - values.deltay;
	if (line.x1 < mlx->x && line.y1 < mlx->y && line.x1 >= 0 && line.y1 >= 0)
		set_pxl(mlx->img_data, line.x1 * 4,
				line.y1 * mlx->size_line, line.clr1);
	while ((line.x0 != line.x1 || line.y0 != line.y1)
				&& line.x0 < mlx->x && line.y0 < mlx->y)
	{
		koroche(mlx, &line, &values);
		line.clr0 = gradient(&values, clr0, clr1, ++i);
	}
}
