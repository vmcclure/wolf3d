/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_textur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:07:41 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/07 19:55:53 by vmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		textcpy(t_mlx *mlx, t_texture text, int x, int y)
{
	float	k;
	int		yp;
	int		y_img;

	k = (float)mlx->rays[x].height / (float)text.height;
	yp = (text.height - (int)(y / k) - 1) * text.width * 3;
	y_img = 400 - (mlx->rays[x].height / 2) + y;
	if (y_img >= 0 && y_img < 800)
	{
		mlx->img_data[x * 4 + y_img * mlx->size_line + 0] =
				text.pixels[mlx->rays[x].vertical * 3 + yp + 0];
		mlx->img_data[x * 4 + y_img * mlx->size_line + 1] =
				text.pixels[mlx->rays[x].vertical * 3 + yp + 1];
		mlx->img_data[x * 4 + y_img * mlx->size_line + 2] =
				text.pixels[mlx->rays[x].vertical * 3 + yp + 2];
	}
}

static void		texture_init(t_texture *text)
{
	text[0] = readbmp("./text/n.bmp");
	text[1] = readbmp("./text/s.bmp");
	text[2] = readbmp("./text/w.bmp");
	text[3] = readbmp("./text/e.bmp");
}

static void		mnogo_if(t_mlx *mlx, t_texture *text, int x, int y)
{
	if (mlx->rays[x].ns == 'N')
		textcpy(mlx, text[0], x, y);
	if (mlx->rays[x].ns == 'S')
		textcpy(mlx, text[1], x, y);
	if (mlx->rays[x].we == 'W')
		textcpy(mlx, text[2], x, y);
	if (mlx->rays[x].we == 'E')
		textcpy(mlx, text[3], x, y);
}

void			put_textur(t_mlx *mlx)
{
	t_texture	text[4];
	int			y;
	int			x;

	texture_init(text);
	x = -1;
	while (++x < 1000)
	{
		y = -1;
		if (400 - (mlx->rays[x].height / 2) + y < 0)
			y = mlx->rays[x].height / 2 - 400 - 1;
		while (++y < mlx->rays[x].height)
		{
			if (400 - (mlx->rays[x].height / 2) + y > 800)
				break ;
			mnogo_if(mlx, text, x, y);
		}
	}
	x = -1;
	while (++x < 4)
		free(text[x].pixels);
}
