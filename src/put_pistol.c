/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmcclure <vmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 22:27:08 by vmcclure          #+#    #+#             */
/*   Updated: 2019/04/08 13:59:01 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	void	mnogo_strok(int x, int y, t_texture *text, t_mlx *mlx)
{
	int			k;

	if (mlx->anim > 4 || mlx->anim < 0)
		mlx->anim = 0;
	k = mlx->anim;
	if (text[mlx->anim].pixels[x / 2 * 4 + (text[k].height - y / 2 - 1)
		* text[k].width * 4 + 0] == 255 && text[k].pixels[x / 2 * 4
		+ (text[k].height - y / 2 - 1) * text[k].width * 4 + 1] == 255
		&& text[k].pixels[x / 2 * 4 + (text[k].height - y / 2 - 1)
		* text[k].width * 4 + 2] == 255)
		x++;
	else
	{
		mlx->img_data[y * mlx->size_line + ((x + 100) * mlx->bpp / 8)
		+ 0] = text[k].pixels[(x / 2) * 4 + (text[k].height - (y / 2)
		- 1) * text[k].width * 4 + 0];
		mlx->img_data[y * mlx->size_line + ((x + 100) * mlx->bpp / 8)
		+ 1] = text[k].pixels[(x / 2) * 4 + (text[k].height - (y / 2)
		- 1) * text[k].width * 4 + 1];
		mlx->img_data[y * mlx->size_line + ((x + 100) * mlx->bpp / 8)
		+ 2] = text[k].pixels[(x / 2) * 4 + (text[k].height - (y / 2)
		- 1) * text[k].width * 4 + 2];
		x++;
	}
}

void			del_text(t_texture *text)
{
	int	i;

	i = -1;
	while (++i < 5)
		free(text[i].pixels);
}

void			put_pistol(t_mlx *mlx)
{
	t_texture	text[5];
	int			x;
	int			y;

	text[0] = readbmp("./text/0/shotgun1.bmp");
	text[1] = readbmp("./text/0/shotgun2.bmp");
	text[2] = readbmp("./text/0/shotgun3.bmp");
	text[3] = readbmp("./text/0/shotgun4.bmp");
	text[4] = readbmp("./text/0/shotgun5.bmp");
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			mnogo_strok(x, y, text, mlx);
			x++;
		}
		y++;
	}
	del_text(text);
}
