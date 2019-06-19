/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtreutel <dtreutel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:55:23 by dtreutel          #+#    #+#             */
/*   Updated: 2019/04/04 16:33:13 by dtreutel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_exit(t_mlx *mlx)
{
	ft_arraydel((void **)mlx->map);
	free(mlx->map);
	mlx->map = 0;
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	exit(0);
	return (0);
}
